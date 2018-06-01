/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyImage.h
 * Author: will
 *
 * Created on 1 de mayo de 2018, 08:54 PM
 */

#ifndef STRATEGYIMAGE_H
#define STRATEGYIMAGE_H
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>      // std::ifstream
#include <iostream>     // std::cout

class StrategyImage {
public:
    StrategyImage();
    StrategyImage(const StrategyImage& orig);
    virtual ~StrategyImage();
    virtual void readImage(int heigth, int width, std::string direction, cv::Mat& image) = 0;
    
private:

};

#endif /* STRATEGYIMAGE_H */

