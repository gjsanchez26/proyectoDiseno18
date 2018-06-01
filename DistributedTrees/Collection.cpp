/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collection.cpp
 * Author: will
 * 
 * Created on 1 de mayo de 2018, 09:06 PM
 */

#include "Collection.h"

Collection::Collection() {
}

Collection::Collection(const Collection& orig) {
}

Collection::~Collection() {
}


void Collection::setImage(StrategyImage* TypeImage){
    Collection::stImage = TypeImage;
}

void Collection::readImage(int height, int width, std::string direction, cv::Mat& image){
    cv::Mat imageTem;
    Collection::stImage->readImage(height,width,direction,imageTem);
    image = imageTem;
    
}