/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   userValidator.cpp
 * Author: gabo
 * 
 * Created on April 18, 2018, 7:34 AM
 */

#include "userValidator.h"

bool userValidator::validateConfiguration(ConfigData& pData){
    /*  WRITE YOUR CODE HERE
     * USER WAY TO VALIDATE CONFIGURATION
     * 
     */
    cout << "User concrete validation with: \n" ;
    pData.printData();
    
    switch( pData.GetTrainningMethod()){
        case 0: {
            cout << "BPC METHOD VALIDATION \n";
            return true;
            break;
        }
        case 1: {
            cout << "OJR METHOD VALIDATION\n";
            return true;

            break;
        }
        case 2: {
            cout << "LATENT METHOD VALIDATION\n";
            return true;
            break;
        }
        default: {
            cout << "CHOOSE METHOD";
            return false;
            break;
        }
            
    
    }

}

