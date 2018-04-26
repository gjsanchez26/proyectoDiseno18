/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   configValidator.h
 * Author: gabo
 *
 * Created on April 18, 2018, 7:27 AM
 */

#ifndef CONFIGVALIDATOR_H
#define CONFIGVALIDATOR_H
#include "ConfigData.h"

using namespace std;

class configValidator {
public:
    virtual bool validateConfiguration(configData &pData) = 0;
    virtual ~configValidator();
    
private:

};

#endif /* CONFIGVALIDATOR_H */

