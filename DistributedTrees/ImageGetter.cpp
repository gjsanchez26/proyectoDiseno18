/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageGetter.cpp
 * Author: will
 * 
 * Created on 29 de abril de 2018, 10:10 PM
 */

#include "ImageGetter.h"




ImageGetter::ImageGetter() {
}

ImageGetter::ImageGetter(const ImageGetter& orig) {
}

ImageGetter::~ImageGetter() {
}

/**
 * Funcion para leer el archivo que contiene la direccion de todas las imagenes en la base de datos 
 * @param directiones
 * @param cont
 */
void ImageGetter::readPath(std::vector<std::string>& directiones, int& cont, std::string path, int startRead, int endRead) {
    std::ifstream file;
    std::string line;
    int numeroLinea = 0;
    //int cont = 0;
    file.open(path.c_str(), std::ifstream::in);
    
    //Leer el archivo hasta que termine.
    while (!file.eof()) {
        
        if(numeroLinea >= startRead && numeroLinea<endRead){
            getline(file, line); //Lee la linea
            directiones.push_back(line); //agrega la linea al vector
        }else{
            getline(file, line); //Lee la linea
        }
        if(numeroLinea == endRead){
            break;
        }
        numeroLinea++;
    }
    

    
}