/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeManager.cpp
 * Author: gabo
 * 
 * Created on May 17, 2018, 4:24 PM
 */

#include "ForestManager.h"

rdf::ForestManager::ForestManager() {
    _status=false;
}

rdf::ForestManager::ForestManager(const ForestManager& orig) {
}

rdf::ForestManager::~ForestManager() {
}

void rdf::ForestManager::initializeForest() {
    for(int i = 0; i < TREE_AMOUNT; i++){
        rdf::Task newTask;
        newTask.setRank(0);
        newTask.setTree(i);
        newTask.setNode(1);
        newTask.setStatus(false); 
        _matrixSteps.push_back(newTask);
        rdf::NodeResult node; 
        _resultMap.insert(std::make_pair(newTask,node));
    } 
}

void rdf::ForestManager::showQueue() {
    for(int i=0; i<_matrixSteps.size(); i++){
        rdf::Task temp = _matrixSteps[i];
        temp.showTask();
    }
}

rdf::Task & rdf::ForestManager::getNextTask() {
    std::cout << "Queue Size: " << _matrixSteps.size()<< "\n";
    rdf::Task &test = _matrixSteps[0];
    //_matrixSteps.erase(_matrixSteps.begin());
    return test;
}

bool rdf::ForestManager::addResuld(NodeResult& pResult) {
    std::cout<<"REDUCE: " << pResult.getResultSize() << "\n";

    _resultMap.find(pResult.getTask())->second.reduce(pResult);
    //_result.reduce(pResult);
    //_result.showTask();
    
    Task leftChild; 
    Task rightChild;
    
    
    leftChild.setRank(pResult.getTask().getRank());
    leftChild.setTree(pResult.getTask().getTree());
    leftChild.setNode(2 * pResult.getTask().getNode());
    leftChild.setStatus(pResult.getTask().isStatus());
    
    rightChild.setRank(pResult.getTask().getRank());
    rightChild.setTree(pResult.getTask().getTree());
    rightChild.setNode(2 * pResult.getTask().getNode()-1);
    rightChild.setStatus(pResult.getTask().isStatus());
    
    _matrixSteps.push_back(leftChild);
    _matrixSteps.push_back(rightChild);
    std::cout<< "Adding child nodes, size: "<<_matrixSteps.size()<<"\n";
    NodeResult result;
    
    _resultMap.insert(std::make_pair(leftChild,result));
    _resultMap.insert(std::make_pair(leftChild,result));
    
    //leftChild.showTask();
    //rightChild.showTask();
    
    
    

    return true;

}


