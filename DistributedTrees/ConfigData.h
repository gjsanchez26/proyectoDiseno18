/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   configData.h
 * Author: gabo
 *
 * Created on April 17, 2018, 10:23 PM
 */
#include <iostream>

#ifndef CONFIGDATA_H
#define CONFIGDATA_H

using namespace std;

class ConfigData {
private:
    const int _vectorAmount     = 0;
    const int _thresholdAmount  = 0;
    const int _treeAmount       = 0;
    const int _testImageAmount  = 0;
    const int _trainImageAmount = 0;
    const int _logVerbosity     = 0;
    const int _noticeTime       = 0;
    const int _threadAmount     = 0;
    const int _trainningMethod  = 0;
    const int _stopMethod       = 0;
    const int _selectionMethod  = 0;
    
public:
    ConfigData();
    ConfigData(const ConfigData& orig);
    ConfigData(const int _vectorAmount, const int _thresholdAmount, const int _treeAmount, const int _testImageAmount, const int _trainImageAmount, const int _logVerbosity, const int _noticeTime, const int _threadAmount, const int _trainningMethod, const int _stopMethod, const int _selectionMethod) :
    _vectorAmount(_vectorAmount), _thresholdAmount(_thresholdAmount), _treeAmount(_treeAmount), _testImageAmount(_testImageAmount), _trainImageAmount(_trainImageAmount), _logVerbosity(_logVerbosity), _noticeTime(_noticeTime), _threadAmount(_threadAmount), _trainningMethod(_trainningMethod), _stopMethod(_stopMethod), _selectionMethod(_selectionMethod) {
    }
    virtual ~ConfigData();
    
    void printData();
    
    const int GetLogVerbosity() const {
        return _logVerbosity;
    }

    const int GetNoticeTime() const {
        return _noticeTime;
    }

    const int GetSelectionMethod() const {
        return _selectionMethod;
    }

    const int GetStopMethod() const {
        return _stopMethod;
    }

    const int GetTestImageAmount() const {
        return _testImageAmount;
    }

    const int GetThreadAmount() const {
        return _threadAmount;
    }

    const int GetThresholdAmount() const {
        return _thresholdAmount;
    }

    const int GetTrainImageAmount() const {
        return _trainImageAmount;
    }

    const int GetTrainningMethod() const {
        return _trainningMethod;
    }

    const int GetTreeAmount() const {
        return _treeAmount;
    }

    const int GetVectorAmount() const {
        return _vectorAmount;
    }      
};

#endif /* CONFIGDATA_H */

