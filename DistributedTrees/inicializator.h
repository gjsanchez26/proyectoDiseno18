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
#include "configData.h"
#ifndef INITIALIZATOR_H
#define INITIALIZATOR_H

class initializator {
public:
    initializator();
    initializator(const initializator& orig);
    initializator(const configData &Data);
    virtual ~initializator();
private:

};

#endif /* INITIALIZATOR_H */

