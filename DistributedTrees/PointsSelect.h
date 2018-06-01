/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PointsSelect.h
 * Author: will
 *
 * Created on 8 de mayo de 2018, 06:14 PM
 */

#ifndef POINTSSELECT_H
#define POINTSSELECT_H

#include <string>
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <vector>
#include "Estructura.h"


class PointsSelect {
public:
    PointsSelect();
    PointsSelect(const PointsSelect& orig);
    virtual ~PointsSelect();
    void generatedPoints(std::string type_Algorithm, std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree);
    
private:
    void generatShoton(std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree);

};

#endif /* POINTSSELECT_H */

