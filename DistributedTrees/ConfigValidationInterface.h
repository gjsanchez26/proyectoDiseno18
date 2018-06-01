/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   configValidator.h
 * Author: gabo
 * This is an interface to validate configurations, you need to create a class a implement this interface overriding validateConfiguration method.
 * Created on April 18, 2018, 7:27 AM
 */

#ifndef CONFIGVALIDATOR_H
#define CONFIGVALIDATOR_H
#include "ConfigData.h"

using namespace std;

class ConfigValidationInterface {
private:
    
public:
    virtual bool validateConfiguration(ConfigData &pData) = 0;
    virtual ~ConfigValidationInterface();


};

#endif /* CONFIGVALIDATOR_H */

