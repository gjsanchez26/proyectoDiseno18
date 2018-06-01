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

ConfigData::ConfigData() {
}

ConfigData::ConfigData(const ConfigData& orig) {
    /*_vectorAmount       = orig._vectorAmount;
        _thresholdAmount    = orig._thresholdAmount;
        _treeAmount         = orig._treeAmount;
        _testImageAmount    = orig._trainImageAmount;
        _logVerbosity       = orig._logVerbosity;
        _noticeTime         = orig._noticeTime;
        _threadAmount       = orig._threadAmount;
        _trainImageAmount   = orig._trainImageAmount;
        _stopMethod         = orig._stopMethod;
        _selectionMethod    = orig._selectionMethod;*/
}

ConfigData::~ConfigData() {
}
void ConfigData::printData(){
    cout << "**** Configuration Info ****"              << '\n';
    cout << "   Vectors: "         << _vectorAmount     << '\n';
    cout << "   Thresholds: "      << _thresholdAmount  << '\n';
    cout << "   Trees: "           << _treeAmount       << '\n';
    cout << "   TestImages: "      << _testImageAmount  << '\n';
    cout << "   TrainImages: "     << _trainImageAmount << '\n';
    cout << "   Verbosity: "       << _logVerbosity     << '\n';
    cout << "   NoticeTime : "     << _noticeTime       << '\n';
    cout << "   Threads : "        << _threadAmount     << '\n';
    cout << "   TrainningMethod: " << _trainningMethod  << '\n';
    cout << "   StopMethod : "     << _stopMethod       << '\n';
    cout << "   SelectionMethod: " << _selectionMethod  << '\n';
}

