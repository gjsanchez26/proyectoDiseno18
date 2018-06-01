/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageManager.h
 * Author: gabo
 *
 * Created on May 27, 2018, 6:55 AM
 */

#include <fstream>      // std::ifstream
#include <iostream>     // std::cout
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <stdio.h>
#include <omp.h>
#include <cmath>
#include "ImageGetter.h"
#include "Collection.h"
#include "LabelImage.h"
#include "DepthImage.h"
#include "Estructura.h"
#include "PointsSelect.h"
#include "Image.h"



#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

class ImageManager {
public:
    ImageManager();
    ImageManager(const ImageManager& orig);
    virtual ~ImageManager();
    void showStructure(bool showImages);
    void setRange(std::pair<int,int> pRange);
    void loadImages();
    std::vector<Estructura::Node> getStructure() const {
        return structure;
    }

    void setStructure(std::vector<Estructura::Node> structure) {
        this->structure = structure;
    }

private:
   
    Image image; //para sacar la estructura
    Estructura estructura; //para visualizar la imagen
    cv::Mat img;  //para sacar la imagen de la estrctura
    std::vector<Estructura::Node> structure; // vector para sacar la estructura
    Estructura::DataMaster dataMaster;
            

            //struture, algortimo, cantidad puntos, height, width, numero de arboles, inicio de lectura, fin de lectura, arbol, node.
              // optine la estructura


            

};

#endif /* IMAGEMANAGER_H */

