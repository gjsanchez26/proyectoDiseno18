/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.h
 * Author: will
 *
 * Created on 8 de mayo de 2018, 08:53 PM
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include "Estructura.h"
#include "Collection.h"
#include "LabelImage.h"
#include "DepthImage.h"

class Image {
public:
    Image();
    Image(const Image& orig);
    virtual ~Image();
    void getStructura (std::vector<Estructura::Node>& structure, Estructura::DataMaster dataMaster);
private:
    void generatedStructureShotton(std::vector<Estructura::Node>& structure, 
            std::string type_Algorithm, int NumPoints, int height, int width, 
            int NumTree, std::string pathDepth, std::string pathlabel, 
            int startRead, int endRead, int tree, int node);

};

#endif /* IMAGE_H */

