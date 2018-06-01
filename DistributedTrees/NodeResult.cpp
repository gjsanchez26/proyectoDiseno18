/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeResult.cpp
 * Author: gabo
 * 
 * Created on May 22, 2018, 3:08 PM
 */

#include "NodeResult.h"

rdf::NodeResult::NodeResult() {
}

rdf::NodeResult::NodeResult(const NodeResult& orig) {
    _resultSize     = orig._resultSize;
    _status         = orig._status;
    _task           = orig._task;
    _matrixResults  = orig._matrixResults;
}

rdf::NodeResult::~NodeResult() {
}

void rdf::NodeResult::reduce(NodeResult& pResult) {
    std::cout << "reducing from ";
    pResult.getTask().showTask();
    _matrixResults.Reduce(pResult._matrixResults);
    
    std::cout << " \n Result left: " << _resultSize++ << "\n";
    if(_resultSize == pResult.getResultSize()){
        _status = true;
        std::cout << "ALL RESULTS from: ";
        pResult.getTask().showTask();
        std::pair<int,int> _featureIndex = pResult._matrixResults.FindBestPair();
        
        rdf::bpc::Features _feature   = pResult.getTask().getFeatureMatrix().GetFeaturesAt(_featureIndex.first);
        float _threshold = pResult.getTask().getFeatureMatrix().GetThresholdAt(_featureIndex.second);
        
        std::cout << "FEATURES1: " << _feature.feature1_.x << "," << _feature.feature1_.y << "\n";
        std::cout << "FEATURES2: " << _feature.feature2_.x << "," << _feature.feature2_.y << "\n";
        std::cout << "THRESHOLS: " << _threshold << "\n";
    }
}


