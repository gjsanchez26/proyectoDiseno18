/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabelImage.cpp
 * Author: will
 * 
 * Created on 1 de mayo de 2018, 09:00 PM
 */

#include "LabelImage.h"

LabelImage::LabelImage() {
}

LabelImage::LabelImage(const LabelImage& orig) {
}

LabelImage::~LabelImage() {
}

/**
 * Funcion para la lectura de la imagen de etiquetas.
 * @param direction
 * @param imageLabel
 */
void LabelImage::readImage(int height, int width, std::string direction, cv::Mat& image) {
    cv::Mat imageLbl(height, width, CV_8UC3);
    std::string rute = direction;
    imageLbl = cv::imread(rute.c_str());

    image = imageLbl;
    
}
