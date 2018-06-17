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


/**
 * This funtion display of the resources of the cluster node
 */
void rdf::Resource::displayResource(){
    std::cout << "Memoria total: "  <<  rdf::Resource::MemTotal << "\n";
    std::cout << "Memoria libre: "  <<  rdf::Resource::MemFree << "\n";
    std::cout << "Frecuencia: "     <<  rdf::Resource::Frequency << "\n";
    std::cout << "Numero de CPUs: " <<  rdf::Resource::CPUs << "\n";
}
