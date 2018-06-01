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
#include "Config.h"
#include "ConfigData.h"
#include "ConfigValidationInterface.h"
#include "userValidator.h"


#ifndef INITIALIZATOR_H
#define INITIALIZATOR_H

namespace rdf {
    /* This class allow to initialize the platform
        */
    class Initializator {
        
        private:
            ConfigData                  *_config;
            ConfigValidationInterface   *_validator;
            
        public:
            Initializator();
            Initializator(const Initializator& orig);
            Initializator(const ConfigData &Data);
            virtual ~Initializator();
            
            void createPlataform();
            
            
    };
}
#endif /* INITIALIZATOR_H */

