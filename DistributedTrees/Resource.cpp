/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.cpp
 * Author: will
 * 
 * Created on 31 de mayo de 2018, 09:13 AM
 */

#include "Resource.h"

rdf::Resource::Resource() {
}

rdf::Resource::Resource(const Resource& orig) {
    MemFree     =   orig.MemFree;
    MemTotal    =   orig.MemTotal;
    Frequency   =   orig.Frequency;
    CPUs        =   orig.CPUs;
    
}

rdf::Resource::~Resource() {
}


void rdf::Resource::displayResource(){
    std::cout << "Memoria total: "  <<  rdf::Resource::MemTotal << "\n";
    std::cout << "Memoria libre: "  <<  rdf::Resource::MemFree << "\n";
    std::cout << "Frecuencia: "     <<  rdf::Resource::Frequency << "\n";
    std::cout << "Numero de CPUs: " <<  rdf::Resource::CPUs << "\n";
}
