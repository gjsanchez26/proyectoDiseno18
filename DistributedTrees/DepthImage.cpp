/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DepthImage.cpp
 * Author: will
 * 
 * Created on 1 de mayo de 2018, 09:20 PM
 */

#include "DepthImage.h"

DepthImage::DepthImage() {
}

DepthImage::DepthImage(const DepthImage& orig) {
}

DepthImage::~DepthImage() {
}
/**
 * Funcion para la lectura de la imagen de profundidad.
 * @param direction
 * @param imageLabel
 */
void DepthImage::readImage(int height, int width, std::string direction, cv::Mat& image) {
    cv::Mat imegeDepth;
    imegeDepth = cv::Mat(height, width, CV_16UC1, cv::Scalar(0));
    std::string rute = direction;
    imegeDepth = cv::imread(rute.c_str(),CV_16UC1);
    image = imegeDepth;
}