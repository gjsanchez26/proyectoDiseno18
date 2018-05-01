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

#define Width 320
#define Height 240

class ImageGetter {
public:
    struct dataInitial {
        cv::Mat imageDepth;
        cv::Mat imageLabel;
    };
    ImageGetter();
    ImageGetter(const ImageGetter& orig);
    virtual ~ImageGetter();
    void setVariables(std::string type_Algorithm, int star_Read, int end_Read); // Entra la estructura o las variables del archivo de configuracion
    void getStructure(std::vector<dataInitial> &estructure); // Le entra una estructura la cual va a llenar con las imagenes                    struct data *datos
private:
    void readPad(std::vector<std::string>& directiones, int& cont); // se encarga de leer el archivo que contiene las imagenes lo asigna a una aareglo input:arreglo, es llamado desde getStructure
    void readImageDepth(std::string direction, std::vector<std::string>& imageDepth); // ingresa un string con el pat, entra una matriz con el fin de llenar con los valores del .dat
    void readImageLabel(std::string direction, cv::Mat& imageLabel); // ingresa un string con el pat, entra un mat con el fin de llenar con los valores del .png
    void readImages(int startLecture, int endLecture);

};

#endif /* IMAGEGETTER_H */

