/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   treeScheduler.h
 * Author: gabo
 *
 * Created on April 26, 2018, 7:43 AM
 */

#ifndef TREESCHEDULER_H
#define TREESCHEDULER_H

#include <vector>
#include "configData.h"
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class treeScheduler {
public:
    treeScheduler();
    pair<int,int> getNextNode();
    void intializateMatix(configData &pData);
    void addResult(pair<int,int> node, pair<int,int> result);
    void showResults();
    void showQueue();
    bool getStatus() {return _status;};
    treeScheduler(const treeScheduler& orig);
    virtual ~treeScheduler();
private:
    vector<pair<int,int>>               _matrixSteps;
    vector<vector<pair<int,int>>>       _matrixResults;
    pair<int,int>                       _nextVector; 
    bool                                _status  =  false;
    

};

#endif /* TREESCHEDULER_H */

