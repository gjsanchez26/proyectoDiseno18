/* 
 * File:   Resources.h
 * Authors: 
 * Gabriel Sanchez
 * Alejandro Gonzalez
 * Wilberth Varela
 *
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

namespace rdf {

    /*
     * This class load in the object resource, the resources of each cluster node
     */
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
        void deleteDocument(); //remove( "myfile.txt" )
        void readDocumentEnd(std::vector<std::string>& vector);
        void convert();

    };
}

#endif /* RESOURCES_H */

