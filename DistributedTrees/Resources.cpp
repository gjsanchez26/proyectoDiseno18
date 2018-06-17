#include <cstring>
#include <string>

#include "Resources.h"

using namespace rdf;

rdf::Resources::Resources() {
}

rdf::Resources::Resources(const Resources& orig) {
}

rdf::Resources::~Resources() {
}

/**
 * This method get to general information of cluster node
 * @param infoNodoCluster
 */
void rdf::Resources::getResources(std::vector<std::string>& infoNodoCluster) {
    std::ifstream meminfo, cpuinfo;
    std::string all = "";
    std::vector<std::string> infoNodoClusterTemp;
    createDocuments();
    convert();

    loadDocuments(meminfo, cpuinfo);

    readDocument(meminfo, all, 0);
    readDocument(cpuinfo, all, 1);
    
    meminfo.close();
    cpuinfo.close();
    writeDocument(all);

    deleteDocument();

    readDocumentEnd(infoNodoClusterTemp);

    infoNodoCluster = infoNodoClusterTemp;
}

/**
 * This method convert the files general to files with 
 * the all information a 2 files only with the information specify
 */
void rdf::Resources::convert() {
    std::ifstream meminfo, cpuinfo;
    meminfo.open("meminfo.txt");
    cpuinfo.open("cpuinfo.txt");
    std::string mem, cpu;

    char c;
    if (meminfo.is_open()) {
        while (!meminfo.eof()) {
            meminfo >> c;
            if (c == '$') {
                mem.append("\n");
            } else {
                mem += c;
            }
        }
    }

    if (cpuinfo.is_open()) {
        while (!cpuinfo.eof()) {
            cpuinfo >> c;
            if (c == '$') {
                cpu.append("\n");
            } else {
                cpu += c;
            }
        }
    }
    
    meminfo.close();
    cpuinfo.close();
    
    std::ofstream omeminfo, ocpuinfo;
    omeminfo.open("meminfo.txt");
    ocpuinfo.open("cpuinfo.txt");
    
    omeminfo << mem;
    ocpuinfo << cpu;
    
    omeminfo.close();
    ocpuinfo.close();

}

/**
 * This method create to files with the imformation of cluster node
 */
void rdf::Resources::createDocuments() {
    system("echo $(cat -E /proc/meminfo) >meminfo.txt");
    system("echo $(cat -E /proc/cpuinfo) >cpuinfo.txt");
}

/**
 * This method load files with the information
 * @param meminfo
 * @param cpuinfo
 */
void rdf::Resources::loadDocuments(std::ifstream& meminfo, std::ifstream& cpuinfo) {
    meminfo.open("meminfo.txt");
    cpuinfo.open("cpuinfo.txt");
}

/**
 * This method read files with information for is to process
 * @param file
 * @param text
 * @param tipo
 */
void rdf::Resources::readDocument(std::ifstream& file, std::string& text, int tipo) {
    std::string line;
    std::string temporal = "";
    if (tipo == 0) {
        temporal = "Memory_info\n";
        while (!file.eof()) {
            getline(file, line); //Lee la linea
            std::string value;
            std::stringstream check1(line);
            while (getline(check1, value, ' ')) {
                if (value.compare(0,9,"MemTotal:") == 0) { //value == "MemTotal:"
                    temporal += line + '\n';
                    
                } else if (value.compare(0,8,"MemFree:")== 0) {
                    temporal += line + '\n';
                    
                }
            }
        }
    } else {
        temporal += "CPU_info\n";
        while (!file.eof()) {
            getline(file, line); //Lee la linea
            std::string value;
            std::stringstream check1(line);
            
            while (getline(check1, value, ' ')) {
                if (value.compare(0,9,"processor") == 0) {
                    temporal += line + '\n'; 
                } else if (value.compare(0,6,"cpuMHz") == 0) {
                    temporal += line + '\n';
                } else if (value.compare(0,8,"cpucores") == 0) {
                    temporal += line + '\n';
                }
            }
        }
    }
    text += temporal;
}

/**
 * This method write only file with information necessary
 * @param final
 */
void rdf::Resources::writeDocument(std::string final) {
    std::ofstream file;
    file.open("Resources.txt");
    file << final;
    file.close();
}

/**
 * This method delete the previous files created for get information
 */
void rdf::Resources::deleteDocument() {
    remove("meminfo.txt");
    remove("cpuinfo.txt");
}

/**
 * This method read file with information necesary for send to cluster nodo master 
 * @param vector
 */
void rdf::Resources::readDocumentEnd(std::vector<std::string>& vector) {
    std::ifstream file;
    std::string line;
    file.open("Resources.txt", std::ifstream::in);
    //Leer el archivo hasta que termine.
    while (!file.eof()) {
        getline(file, line); //Lee la linea
        vector.push_back(line); //agrega la linea al vector
    }
}

/**
 * This method create object with the information necessary
 * @param infoNodoCluster
 * @param resourcesNodo
 */
void rdf::Resources::createObjet(std::vector<std::string> infoNodoCluster, Resource& resourcesNodo){
    
    std::string memtotal = infoNodoCluster[1];
    std::string valueMemTotal = "";
    bool readValueTotal = false;
    for (unsigned int i = 0; i < memtotal.size(); i++) {
        if(memtotal[i] == 'k'){
            readValueTotal = false;
        }
        if (readValueTotal) { 
            valueMemTotal = valueMemTotal + memtotal[i]; 
        }
        if(memtotal[i] == ':'){
            readValueTotal = true;
        }

    }

    std::string memfree = infoNodoCluster[2];
    std::string valueMemFree = "";
    bool readValueFree = false;
    for (unsigned int i = 0; i < memfree.size(); i++) {
        if(memfree[i] == 'k'){
            readValueFree = false;
        }
        if (readValueFree) { 
            valueMemFree = valueMemFree + memfree[i]; 
        }
        if(memfree[i] == ':'){
            readValueFree = true;
        }
    }
    
    
    
    std::string frequency = infoNodoCluster[5];
    std::string valueFrequency = "";
    bool readValueFrequency = false;
    for (unsigned int i = 0; i < frequency.size(); i++) {
        if(frequency[i] == 'k'){
            readValueFrequency = false;
        }
        if (readValueFrequency) { 
            valueFrequency = valueFrequency + frequency[i]; 
        }
        if(frequency[i] == ':'){
            readValueFrequency = true;
        }
    }
    
    
    
    int cpus = 0; 
    for (unsigned int i = 3; i < infoNodoCluster.size(); i++) {
        std::string valor = infoNodoCluster[i];
        if(!valor.compare(0,9,"processor")){
            cpus += 1;
        }
    }
    
    resourcesNodo.CPUs = cpus;
    resourcesNodo.Frequency = atoi(valueFrequency.c_str());
    resourcesNodo.MemFree = atoi(valueMemFree.c_str());
    resourcesNodo.MemTotal = atoi(valueMemTotal.c_str());
    
}

