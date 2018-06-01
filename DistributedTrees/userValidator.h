/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   userValidator.h
 * Author: gabo
 *
 * Created on April 18, 2018, 7:34 AM
 */

#ifndef USERVALIDATOR_H
#define USERVALIDATOR_H

#include "ConfigValidationInterface.h"
#include "ConfigData.h"

class userValidator: public ConfigValidationInterface {
public:
    //userValidator();
    bool validateConfiguration(ConfigData &pData);
    //userValidator(const userValidator& orig);
private:

};

#endif /* USERVALIDATOR_H */

