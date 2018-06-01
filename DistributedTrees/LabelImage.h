/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabelImage.h
 * Author: will
 *
 * Created on 1 de mayo de 2018, 09:00 PM
 */

#ifndef LABELIMAGE_H
#define LABELIMAGE_H

#include <iostream>
#include "StrategyImage.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


class LabelImage: public StrategyImage {
public:
    LabelImage();
    LabelImage(const LabelImage& orig);
    virtual ~LabelImage();
    virtual void readImage(int height, int width, std::string direction, cv::Mat& image);

    
private:

};

#endif /* LABELIMAGE_H */

