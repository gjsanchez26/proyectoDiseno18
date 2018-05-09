/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   treeScheduler.cpp
 * Author: gabo
 * 
 * Created on April 26, 2018, 7:43 AM
 */

#include "treeScheduler.h"

treeScheduler::treeScheduler() {
}

treeScheduler::treeScheduler(const treeScheduler& orig) {
}

treeScheduler::~treeScheduler() {
}
void treeScheduler::intializateMatix(configData &pData) {
    for(int i=0;i<TREE_AMOUNT;i++){
        vector<pair<int,int>> row;
        pair<int,int> root (-1,-1);
        row.push_back(root);
        _matrixResults.push_back(row);
    }
        
    for(int i=0;i<NODE_AMOUNT;i++){
        vector<pair<int,int>> row;
        for(int j = 0; j<TREE_AMOUNT;j++){
            pair<int,int> init(i,j);
            row.push_back(init);
        }
        _matrixSteps.push_back(row);

    }
    showResults();
    showQueue();
   // _matrixSteps.push_back(_n)
    
}
pair<int, int> treeScheduler::getNextNode(int pNode) {
    
    showQueue();
    pair<int,int> toReturn;
    if(_matrixSteps.at(pNode).size() > 0){
        toReturn.first = _matrixSteps.at(pNode).front().first;
        toReturn.second = _matrixSteps.at(pNode).front().second;
        _matrixSteps.at(pNode).erase(_matrixSteps.at(pNode).begin());
        return toReturn;
    }
    else if(_matrixSteps.at(pNode).size()==0){
        cout << "NO ELEMENTS IN QUEUE \n";
        toReturn.first  = -1;
        toReturn.second = -1;
        return toReturn;
    }
    else {
        toReturn.first  = -1;
        toReturn.second = -1;
        return toReturn;
    }
}

void treeScheduler::addResult(int pIP, pair<int, int> pNode, pair<int, int> result) {
    _matrixResults.at(pNode.first).at(pNode.second) = result;
    pair<int,int> newNode(-1,-1);
    if(pNode.first == _matrixResults.size()-1){
        _nextVector.first  = pNode.first;
        _nextVector.second = pNode.second+1;
        _matrixSteps.at(pIP).push_back(_nextVector);
        
        _nextVector.first  = pNode.first;
        _nextVector.second = pNode.second+2;
        _matrixSteps.at(pIP).push_back(_nextVector);
        
        _matrixResults.at(pNode.first).push_back(newNode);

    }
    else {
        _nextVector.first  = pNode.first;
        _nextVector.second = pNode.second+1;
        _matrixSteps.at(pIP).push_back(_nextVector);
        
        _nextVector.first  = pNode.first;
        _nextVector.second = pNode.second+2;
        _matrixSteps.at(pIP).push_back(_nextVector);
        
        
        _matrixResults.at(pNode.first).push_back(newNode);
        
    }
    showQueue();
    showResults();
    
}

void treeScheduler::showResults() {
    for(int i = 0; i< _matrixResults.size(); i++ ){
        for(int j = 0; j<_matrixResults.at(i).size(); j++){
            cout << "(" << _matrixResults.at(i).at(j).first << "," << _matrixResults.at(i).at(j).second << ") ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void treeScheduler::showQueue(){
        cout << "Queue: \n";
        for(int i = 0; i<_matrixSteps.size(); i++){
            for(int j = 0; j < _matrixSteps.at(i).size();j++){
                    cout << "(" << _matrixSteps.at(i).at(j).first << "," << _matrixSteps.at(i).at(j).second << ") ";
            }
            cout << "\n";
        }
        cout << "\n";
}








