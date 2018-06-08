/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueThread.cpp
 * Author: will
 * 
 * Created on 22 de mayo de 2018, 09:03 AM
 */

#include <exception>

#include "QueueThread.h"
#include "Scheduler.h"
#include "NodeTraineeBPC.h"
#include "TrainerBPC.h"

QueueThread::QueueThread() {
}

QueueThread::QueueThread(const QueueThread& orig) {
}

QueueThread::~QueueThread() {
}


void init(std::vector<Estructura::Node> &structure, rdf::Task& task, rdf::NodeResult & nodeResult) {
    std::cout << "********************************************** SLAVE " << task.getRank() << " is TRAINNING *************************************\n";
    rdf::bpc::NodeTrainee<rdf::bpc::Cell>   _node;
    rdf::NodeResult *nodeResultTemp = new rdf::NodeResult();
    _node.SetTreeId(task.getTree());
    _node.SetNodeId(task.getNode());
    _node.GetMatrix().AddFeaturesMat(task.getFeatureMatrix());
    //std::cout << "SIZE " << structure.size() <<"\n";
    
    cv::Mat img = structure[0].imageLabel;
    
    
    rdf::bpc::Trainer trainer;
    trainer.Train(&_node,structure, nodeResult); // cambiar para meter nodeResult
    
//    nodeResult = nodeResultTemp;
    //std::cout << "        SIZE " << img<< "\n"; 
    
}

void QueueThread::run() {
    std::unique_lock<std::mutex> lck(mtx);
    
    
    rdf::bpc::NodeTrainee<rdf::bpc::Cell>   _node;
    _node.SetTreeId(task.getTree());
    _node.SetNodeId(task.getNode());
    _node.GetMatrix().AddFeaturesMat(task.getFeatureMatrix());
    
    
    //while (1) {
    //lck.lock();

    while (!ready) {
        /*if (!tasks.empty()) {
            sync();
        }*/
        cv.wait(lck);
        //lck.lock();
    }
    ready = false;
    
    thread = std::thread(init, std::ref(structure), std::ref(task), std::ref(nodeResult));
    if (QueueThread::thread.joinable()) {
        //Scheduler scheduler;
        //scheduler.addThreadQueue(*this);
        QueueThread::thread.join();

    }


    //}
}

void QueueThread::connect(std::vector<Estructura::Node> structure, rdf::Task task, 
std::priority_queue<rdf::Task> tasks, rdf::NodeResult &nodeResult) {
    QueueThread::structure = structure;
    QueueThread::task = task;
    QueueThread::tasks = tasks;;

    
    
    sync();
    run();

}

void QueueThread::sync() {
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    lck.unlock();
    cv.notify_one();
}