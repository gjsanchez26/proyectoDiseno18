/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DepthImage.h
 * Author: will
 *
 * Created on 1 de mayo de 2018, 09:20 PM
 */

#ifndef DEPTHIMAGE_H
#define DEPTHIMAGE_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "StrategyImage.h"

class DepthImage: public StrategyImage {
public:
    DepthImage();
    DepthImage(const DepthImage& orig);
    virtual ~DepthImage();
    virtual void readImage(int height, int width, std::string direction, cv::Mat& image);
private:

};

#endif /* DEPTHIMAGE_H */