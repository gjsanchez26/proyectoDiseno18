/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Task.cpp
 * Author: gabo
 * 
 * Created on May 17, 2018, 4:10 PM
 */

#include "Task.h"

rdf::Task::Task() {
    _featureMatrix.SetMatrixSize(VECTOR_AMOUNT,THRESHOLD_AMOUNT);
    _featureMatrix.SetThresholdsNumRange(100,0);
    _featureMatrix.SetFeaturesNumRange(100,0);
    _featureMatrix.GenerateVectors();
    //_featureMatrix.Print();
}

rdf::Task::Task(const Task& orig) {
    _rank           = orig._rank;
    _tree           = orig._tree;
    _node           = orig._node;
    _status         = orig._status;
    _featureMatrix  = orig._featureMatrix;
}


rdf::Task::~Task() {
    
}

rdf::Task::Task( int _rank,  int _tree,  int _node, bool _status) {
    _rank = _rank;
    _tree = _tree;
    _node = _node;
    _status = _status;
}

void rdf::Task::showTask() {
    std::cout << "{ " <<_rank <<  "," << _tree << "," << _node <<"," <<_status << " } \n";
}

void rdf::Task::reduce(Task& pTask) {
    _rank   = _rank + pTask.getRank();
    _tree   = _tree + pTask.getTree();
    _node   = _node + pTask.getNode();
    _status = pTask.isStatus();   
}
