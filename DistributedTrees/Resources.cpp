/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resources.cpp
 * Author: will
 * 
 * Created on 1 de mayo de 2018, 02:45 PM
 */

#include <cstring>
#include <string>

#include "Resources.h"

Resources::Resources() {
}

Resources::Resources(const Resources& orig) {
}

Resources::~Resources() {
}

void Resources::getResources(std::vector<std::string>& infoNodoCluster) {
    std::ifstream meminfo, cpuinfo;
    std::string all = "";
    std::vector<std::string> infoNodoClusterTemp;
    createDocuments();
    convetir();

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

void Resources::convetir() {
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

void Resources::createDocuments() {
    system("echo $(cat -E /proc/meminfo) >meminfo.txt");
    system("echo $(cat -E /proc/cpuinfo) >cpuinfo.txt");
}

void Resources::loadDocuments(std::ifstream& meminfo, std::ifstream& cpuinfo) {
    meminfo.open("meminfo.txt");
    cpuinfo.open("cpuinfo.txt");
}

void Resources::readDocument(std::ifstream& file, std::string& text, int tipo) {
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

void Resources::writeDocument(std::string final) {
    std::ofstream file;
    file.open("Resources.txt");
    file << final;
    file.close();
}

void Resources::deleteDocument() {
    remove("meminfo.txt");
    remove("cpuinfo.txt");
}

void Resources::readDocumentEnd(std::vector<std::string>& vector) {
    std::ifstream file;
    std::string line;
    file.open("Resources.txt", std::ifstream::in);
    //Leer el archivo hasta que termine.
    while (!file.eof()) {
        getline(file, line); //Lee la linea
        vector.push_back(line); //agrega la linea al vector
    }
}

void Resources::createObjet(std::vector<std::string> infoNodoCluster, rdf::Resource& resourcesNodo){
    
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
    
    resourcesNodo.setCPUs      (cpus);
    resourcesNodo.setFrequency (atoi(valueFrequency.c_str()));
    resourcesNodo.setMemFree   (atoi(valueMemFree.c_str()));
    resourcesNodo.setMemTotal  (atoi(valueMemTotal.c_str()));
    
    
    
    
}
