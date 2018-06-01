/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TrainManager.cpp
 * Author: gabo
 * 
 * Created on May 26, 2018, 8:25 PM
 */

#include "TrainManager.h"

rdf::TrainManager::TrainManager() {

}

rdf::TrainManager::TrainManager(const TrainManager& orig) {
}

rdf::TrainManager::~TrainManager() {
}

bool rdf::TrainManager::validateConfiguration() {
   _initializator.createPlataform();
   return true;
}

bool rdf::TrainManager::initPlatform() {
   // _manager.initializeForest();
    _distributor.transferResources();
    _distributor.transferRanges();
    return true;
}

void rdf::TrainManager::sendingNodes() {
    /*
    for(int i = 0; i < _manager.getMatrixSteps().size(); i++){
    
        //_manager.showQueue();
        rdf::Task tast = _manager.getMatrixSteps()[i];
        tast.showTask();
        _distributor.transferNodes(tast);
        
    }
    
    for(int i = 0; i < _manager.getMatrixSteps().size(); i++){
    
        //_manager.showQueue();
        rdf::Task tast = _manager.getMatrixSteps()[i];
        std::vector<std::string> _results;
        _results.push_back("hello");
        _results.push_back("world");
        rdf::NodeResult node;
        node.setTask(tast);
        _distributor.transferResults(node,_manager);
    }*/
 
}

void rdf::TrainManager::sendingResults() {
    rdf::Task testTask = rdf::Task(1,1,0,0);
    rdf::NodeResult test;
    test.setTask(testTask);    
    test.getTask().showTask();
}






