/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   configData.cpp
 * Author: gabo
 * 
 * Created on April 17, 2018, 10:23 PM
 */

#include "ConfigData.h"

configData::configData() {
}

configData::configData(const configData& orig) {
}

configData::~configData() {
}
void configData::printData(){
    cout << "**** Configuration Info ****" << '\n';
    cout << "   Vectors: " << _vectorAmount << '\n';
    cout << "   Thresholds: " << _thresholdAmount << '\n';
    cout << "   Trees: " << _treeAmount << '\n';
    cout << "   TestImages: " << _testImageAmount << '\n';
    cout << "   TrainImages: " << _trainImageAmount << '\n';
    cout << "   Verbosity: " << _logVerbosity << '\n';
    cout << "   NoticeTime : " << _noticeTime << '\n';
    cout << "   Threads : " << _threadAmount << '\n';
    cout << "   TrainningMethod: " << _trainningMethod << '\n';
    cout << "   StopMethod : " << _stopMethod << '\n';
    cout << "   SelectionMethod: " << _selectionMethod << '\n';
    
    

}

