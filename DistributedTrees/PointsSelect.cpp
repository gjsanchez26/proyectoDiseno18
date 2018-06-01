/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointsSelect.cpp
 * Author: will
 * 
 * Created on 8 de mayo de 2018, 06:14 PM
 */

#include "PointsSelect.h"

PointsSelect::PointsSelect() {
}

PointsSelect::PointsSelect(const PointsSelect& orig) {
}

PointsSelect::~PointsSelect() {
}

void PointsSelect::generatedPoints(std::string type_Algorithm, std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree){
    
    std::vector<Estructura::Pixel> temporal;
    if(type_Algorithm.compare(0,7,"shotton") == 0){
        generatShoton(temporal, NumPoints, height, width, NumTree);
        
    }
    points = temporal;
}

void PointsSelect::generatShoton(std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree){
    
    
    std::vector<int> start (NumTree,0);
    Estructura::Pixel pixelTemp;
    
    for (int i = 0; i < NumPoints; i++) {
        pixelTemp.point = cv::Point((rand() % (height - 0)),((rand() % (width - 0))));
        pixelTemp.ubicacion = start;
        points.push_back(pixelTemp);
    }
}
