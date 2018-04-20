/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   initializator.h
 * Author: gabo
 *
 * Created on April 17, 2018, 11:46 PM
 */
#include "config.h"
#include "configData.h"
#include "configValidator.h"
#include "userValidator.h"


#ifndef INITIALIZATOR_H
#define INITIALIZATOR_H

class initializator {
public:
    initializator();
    initializator(const initializator& orig);
    void createPlataform();
    initializator(const configData &Data);
    virtual ~initializator();
private:
    configData       *_config;
    configValidator  *_validator;

};

#endif /* INITIALIZATOR_H */

