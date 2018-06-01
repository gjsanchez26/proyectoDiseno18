/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resources.h
 * Author: will
 *
 * Created on 1 de mayo de 2018, 02:45 PM
 */

#ifndef RESOURCES_H
#define RESOURCES_H
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <vector>

#include "Resource.h"

class Resources {
public:
    Resources();
    Resources(const Resources& orig);
    virtual ~Resources();
    void getResources(std::vector<std::string>& infoNodoCluster);
    void createObjet(std::vector<std::string> infoNodoCluster, rdf::Resource &resourcesNodo);
private:
    void createDocuments();
    void loadDocuments(std::ifstream& meminfo, std::ifstream& cpuinfo);
    void readDocument(std::ifstream& file, std::string& text, int tipo); // tipo 0=memoria 1= cpu
    void writeDocument(std::string final);
    void deleteDocument();  //remove( "myfile.txt" )
    void readDocumentEnd(std::vector<std::string>& vector);
    void convetir();

};

#endif /* RESOURCES_H */

