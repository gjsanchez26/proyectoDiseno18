/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estructura.cpp
 * Author: will
 * 
 * Created on 8 de mayo de 2018, 02:59 PM
 */

#include "Estructura.h"


Estructura::Estructura() {
}

Estructura::Estructura(const Estructura& orig) {
}

Estructura::~Estructura() {
}

void Estructura::seeImageDepth(int height, int width, cv::Mat imageDepth){
    cv::Mat depTem;
    depTem = cv::Mat(height, width, CV_16UC1, cv::Scalar(0));
    
    int mayor = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cv::Scalar intensity = imageDepth.at<unsigned short>(i, j);
            if(mayor < (int) intensity.val[0]){
                mayor = intensity.val[0];
            }
        }
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cv::Scalar intensity = imageDepth.at<unsigned short>(i, j);
            int valor = intensity.val[0];
            valor = ((255*valor)/mayor);
            cv::Scalar temp = valor;
            depTem.at<uchar>(i,j)= temp.val[0];     
        }
    }
    cv::namedWindow( "Original image", CV_WINDOW_AUTOSIZE ); 
    cv::imshow( "Original image", depTem ); 
    cv::waitKey(2000);
}

void Estructura::seeImageLabel(cv::Mat& imageLabel){
    cv::namedWindow( "Original image", CV_WINDOW_AUTOSIZE ); 
    cv::imshow( "Original image", imageLabel ); 
    cv::waitKey(2000);
}
