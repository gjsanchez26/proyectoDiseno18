/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageManager.cpp
 * Author: gabo
 * 
 * Created on May 27, 2018, 6:55 AM
 */

#include "ImageManager.h"

ImageManager::ImageManager() {
    dataMaster.NumPoints = 15;
    dataMaster.height = 240;
    dataMaster.width = 320;
    dataMaster.NumTree = 3;
    dataMaster.tree = 0;
    dataMaster.node = 0;
    dataMaster.type_Algorithm = "shotton";
}

ImageManager::ImageManager(const ImageManager& orig) {
}

ImageManager::~ImageManager() {
}

void ImageManager::setRange(std::pair<int, int> pRange) {
    dataMaster.startRead = pRange.first;
    dataMaster.endRead = pRange.second;
}

void ImageManager::loadImages() {
    image.getStructura(structure, dataMaster);
    
}

void ImageManager::showStructure(bool showImages) {
    //desmostracion de la estructura esta bien
    for (int i = 0; i < structure.size(); i++) {
        img = structure[i].imageLabel;  
        std::vector<Estructura::Pixel> pixel = structure[i].points; 
        if(showImages){
            estructura.seeImageLabel(img);
            estructura.seeImageDepth(240,320,img);
        }
        else {
            for (int j = 0; j < pixel.size(); j++) {
                std::cout <<  pixel[j].point<< "\n";
            }
        }    
    }
}




