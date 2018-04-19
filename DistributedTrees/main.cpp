/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabo
 *
 * Created on April 17, 2018, 10:16 PM
 */

#include <iostream>
#include "configData.h"
#include "configValidator.h"
#include "userValidator.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Hellow World \n";
    /* Test 1: Objeto Configuracion
     *    configData *data = new configData(0,1,2,3,4,5,6,7,8,9,10);
          data->printData();
     */
    
    configData *data = new configData(0,1,2,3,4,5,6,7,2,9,10);
    configValidator *validator = new userValidator(); // Utilizacion de interfaz por medio de la clase implementada por usuario
    validator->validateConfiguration(*data);
            

    return 0;
}

