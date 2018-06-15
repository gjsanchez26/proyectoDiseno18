/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DistributionManager.cpp
 * Author: gabo
 * 
 * Created on May 22, 2018, 8:30 AM
 */

#include <boost/mpi/communicator.hpp>

#include "DistributionManager.h"
#include "BestFeatureMsg.h"
#include "Resource.h"
#include "Resources.h"


rdf::DistributionManager::DistributionManager() {}
rdf::DistributionManager::DistributionManager(const DistributionManager& orig) {
    _imageRanges    = orig._imageRanges;
    _myImageManager = orig._myImageManager;
    _myRange        = orig._myRange;        
}
rdf::DistributionManager::~DistributionManager() {}

void rdf::DistributionManager::waitingResults() {
    while(true){
        std::cout << "WAITING THREAD \n";
        rdf::NodeResult newResult;
        _world.recv(boost::mpi::any_source, 2, newResult); 
        newResult.getTask().showTask();
        _forestManager.addResuld(newResult);            
        _forestManager.showQueue();
        
    }
}

void rdf::DistributionManager::sendingResults() {
    while(true){
        
        if(!_scheduler.getResults().empty()) {
            std::cout << "SENDING THREAD \n";
            _world.send(0, 2,_scheduler.getResults().front()) ; 
            _scheduler.getResults().pop();
            
        }
    }
}

/**
 * This function send and receive messages about node resources
 */
void rdf::DistributionManager::transferResources() {
    
    if (_world.size() <= 1) {
        std::cout << "Need more than 1 processes to play around." << std::endl;
    }
    else { 
        if(_world.rank() != 0){             // MASTER PROCESS
           // CREATING RESOURCES RESPONSE (WILL) 
            Resources _resource;
            std::vector<std::string> _vector;
            _resource.getResources(_vector);
            rdf::Resource _node;
            _resource.createObjet(_vector,_node);
            _node.displayResource();
            _world.send(0,0,_node);  
            std::cout << "Slave "<<_world.rank()<< " have send resources \n";
        }
        else {                             // SLAVE PROCESS

            Resource _nodeInfo;
            std::string response; 
            int i = 1;
            do {                            // receive all responses all resourc
                _world.recv(boost::mpi::any_source, boost::mpi::any_tag,_nodeInfo);
                std::cout << "Master Received Resources \n";
                _nodeInfo.displayResource();
                _imageDistpatcher.addResource(_nodeInfo);
                //_clusterResourses.push_back(response);
                i++;
            }while(i<_world.size());
            _imageDistpatcher.assignRanges(_world.size()-1,false); // Assign ranges according with number of process.
            _imageDistpatcher.showRanges();
        }
    }
}
/**
 * This function send and receive messages about image ranges
 */
void rdf::DistributionManager::transferRanges() {

    if (_world.size() <= 1) {
        std::cout << "Need more than 1 processes to play around." << std::endl;
    }
    else { 
        if(_world.rank()==0){                                           // MASTER PROCESS
            for(int i = 1; i<_world.size(); i++){
                _world.send(i,0,_imageDistpatcher.getImagesRanges().at(i-1)); // Send specific rank to each process.
            }
        }
        else{                                                           // SLAVE PROCESS                       
            _world.recv(0, 0, _myRange);                                // Receive  message from master 
            std::cout << "Process #" << _world.rank() << " will work with [" << _myRange.first << "," << _myRange.second<< "] \n" ;
            _myImageManager.setRange(_myRange);                         // Set range to imageManager
            const clock_t begin_time = clock();
            _myImageManager.loadImages(); 
            std::cout << "Time loading images  Slave" << _world.rank() << " : "  << float( clock () - begin_time ) /double(CLOCKS_PER_SEC) << " seconds\n";                        
            //_myImageManager.showStructure(false);                        // Muestra el contenido de la estructura (0: pixeles, 1: C_Imagenes)
        }
    }
}

/**
 *  This function allows to send a Task that will be process by every cluster node.
 * @param pTask // Task to process include (Rank,Tree, Node, Status, FeatureMatrix)
 */
void rdf::DistributionManager::transferNodes(Task& pTask) {
    if (_world.size() <= 1) {
    std::cout << "Need more than 1 processes to play around." << std::endl;
    }
    else { 
        if(_world.rank() == 0){                                           // MASTER PROCESS
            broadcast(_world, pTask, 0);                                  // Send the task to every process in the cluster
            std::cout << "Master Send (" << pTask.getRank() << "," << pTask.getTree() <<","
                    << pTask.getNode() << "," << pTask.isStatus()<< "] \n" ;
                        int i = 0;
                        std::string response;
                        do {
                            _world.recv(boost::mpi::any_source, boost::mpi::any_tag,response); // Ensure that slave receive the node
                            std::cout << "Master Received Confirmations " << response  << "\n";
                            //_clusterResourses.push_back(response);
                            i++;
                        } while(i<_world.size()-1); 
        }   
        else {                                                          // SLAVE PROCESS
            Task toProcess;                                             // Each slave receive the task;
            _world.recv(boost::mpi::any_source, boost::mpi::any_tag, toProcess);
            std::cout << "Process #" << _world.rank() << " node to process (" 
            << toProcess.getRank() << "," << toProcess.getTree() << ","
            << toProcess.getNode() << "," << toProcess.isStatus()<< "] \n" ;
            std::string response = "OK_" + std::to_string(_world.rank()); // Confirmation Message for master node
            _world.send(0,0,response);                                    // Send confirmation about received node
            //PROCESAR TAREA; 
           // _scheduler.assingTask(_myImageManager.getStructure(),toProcess);
            
            int time = rand() % 1000000 + 10000;
            usleep(time);
        }
    }
}

/**
 *  This messages is to ensure that all the process are running alive.
 */
void rdf::DistributionManager::transferBeacon() {
    if (_world.size() <= 1) {
    std::cout << "Need more than 1 processes to play around." << std::endl;
    }
    else { 
        if(_world.rank() == 0){                                         // MASTER PROCESS
            std::string log = "logInfo";                               
            broadcast(_world, log, 0);                                  // Send the task to every process in the cluster
            std::cout << "Master asking for log info log\n";
            std::string response;
            int i = 1;
            do {                                                        // Wait all the responses 
                _world.recv(boost::mpi::any_source, boost::mpi::any_tag,response);
                std::cout << "Master Receive log information " << response  << "\n";
                i++;
            }while(i<_world.size()); 
        }    
        else {
            std::string logInfo;
            _world.recv(boost::mpi::any_source, boost::mpi::any_tag, logInfo);
            std::string response = "LOG_" + std::to_string(_world.rank());
            _world.send(0,0,response);
        }
    }

}
/**
 * This function allows to send the results to the master node. 
 * @param pResult
 * @param pForest
 */
void rdf::DistributionManager::transferResults() {
    if (_world.size() > 1) {
        if(_world.rank() != 0){
            std::thread t1(&rdf::DistributionManager::sendingResults, rdf::DistributionManager());
            t1.detach();
            
        }
        else{  
            std::thread t2(&rdf::DistributionManager::waitingResults, rdf::DistributionManager());
            t2.detach();
        }
    }
    else { 
        std::cout << "Need more than 1 processes to play around." << std::endl;
    }
}

/**
 * This function allows to send the best feature in order to classify images. 
 * @param feature
 * @param vector1
 * @param vector2
 */
void rdf::DistributionManager::transferBestFeature(rdf::bpc::BestFeatureMsg pFeature) {
     if (_world.size() <= 1) {
    std::cout << "Need more than 1 processes to play around." << std::endl;
    }
    else { 
        if(_world.rank() == 0){
            rdf::bpc::BestFeatureMsg _bestFeature;
            broadcast(_world, _bestFeature, 0);
            std::cout << "Master is sending best feature\n";
        }    
        else {
             rdf::bpc::BestFeatureMsg _bestFeature;
            _world.recv(boost::mpi::any_source, boost::mpi::any_tag, _bestFeature);

        }
    }
}

/**
 *
 * @param pForest
 */
void rdf::DistributionManager::transferTrainStart(ForestManager & pForest) {
    if (_world.size() <= 1) {
    std::cout << "Need more than 1 processes to play around." << std::endl;
    }
    else { 
        //if(_world.rank() != 0){
            //START WILL PROCESS 
            
        }
       // else{
            //ACTIVATE FLAG OR SHT
            
            
            
       // } 
    //}
    
}




