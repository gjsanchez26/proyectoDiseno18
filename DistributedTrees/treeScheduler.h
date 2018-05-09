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
#include "config.h"
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class treeScheduler {
public:
    treeScheduler();
    treeScheduler(const treeScheduler& orig);
    vector<vector<pair<int, int> > > getMatrixResults() const {
        return _matrixResults;
    }

    void setMatrixResults(vector<vector<pair<int, int> > > _matrixResults) {
        this->_matrixResults = _matrixResults;
    }

    vector<vector<pair<int, int> > > getMatrixSteps() const {
        return _matrixSteps;
    }

    void setMatrixSteps(vector<vector<pair<int, int> > > _matrixSteps) {
        this->_matrixSteps = _matrixSteps;
    }

    pair<int, int> getNextVector() const {
        return _nextVector;
    }

    void setNextVector(pair<int, int> _nextVector) {
        this->_nextVector = _nextVector;
    }

    bool isStatus() const {
        return _status;
    }

    void setStatus(bool _status) {
        this->_status = _status;
    }

    pair<int,int> getNextNode(int pTree);
    void intializateMatix(configData &pData);
    void addResult(int pIP, pair<int,int> node, pair<int,int> result);
    void showResults();
    void showQueue();
    bool getStatus() {return _status;};
    
    virtual ~treeScheduler();
private:
    vector<vector<pair<int,int>>>       _matrixSteps;
    vector<vector<pair<int,int>>>       _matrixResults;
    pair<int,int>                       _nextVector; 
    bool                                _status  =  false;
    

};

#endif /* TREESCHEDULER_H */

