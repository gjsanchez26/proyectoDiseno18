/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageGetter.h
 * Author: will
 *
 * Created on 29 de abril de 2018, 10:10 PM
 */

#ifndef IMAGEGETTER_H
#define IMAGEGETTER_H




#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>      // std::ifstream
#include <iostream>     // std::cout
#include <vector>
#include <stdio.h>



#define Width 320
#define Height 240

class ImageGetter {
public:
    ImageGetter();
    ImageGetter(const ImageGetter& orig);
    virtual ~ImageGetter();
    void readPath(std::vector<std::string>& directiones, int& cont, std::string path, int startRead, int endRead); // se encarga de leer el archivo que contiene las imagenes lo asigna a una aareglo input:arreglo, es llamado desde getStructure

private:
    

};

#endif /* IMAGEGETTER_H */

