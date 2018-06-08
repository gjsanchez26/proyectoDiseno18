/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.cpp
 * Author: will
 * 
 * Created on 8 de mayo de 2018, 08:53 PM
 */

#include "Image.h"
#include "ImageGetter.h"
#include "Collection.h"
#include "PointsSelect.h"

Image::Image() {
}

Image::Image(const Image& orig) {
}

Image::~Image() {
}

void Image::getStructura(std::vector<Estructura::Node>& structure, Estructura::DataMaster dataMaster) {
    std::string PathDepthImage = "/home/RDF/code/DistributedTrees/Database/pathDepth.txt";
    std::string PathLabelImage = "/home/RDF/code/DistributedTrees/Database/pathLabel.txt";


    std::vector<Estructura::Node> structureTemp;
    if (dataMaster.type_Algorithm.compare(0, 7, "shotton") == 0) {
        generatedStructureShotton(structureTemp, dataMaster.type_Algorithm, dataMaster.NumPoints, dataMaster.height, dataMaster.width,
                dataMaster.NumTree, PathDepthImage, PathLabelImage, dataMaster.startRead, dataMaster.endRead, dataMaster.tree, dataMaster.node);
    }


    structure = structureTemp;
}

void Image::generatedStructureShotton(std::vector<Estructura::Node>& structure,
        std::string type_Algorithm, int NumPoints, int height, int width,
        int NumTree, std::string pathDepth, std::string pathlabel,
        int startRead, int endRead, int tree, int node) {

    ImageGetter imageGetter;
    LabelImage lblImage;
    DepthImage depthImage;
    Collection collection;
    cv::Mat imageDepth, imageLabel;

    //lee las direciones del path
    std::vector<std::string> directionesDepth;
    std::vector<std::string> directionesLabel;
    int NumLines = 0;

    imageGetter.readPath(directionesDepth, NumLines, pathDepth, startRead, endRead);
    imageGetter.readPath(directionesLabel, NumLines, pathlabel, startRead, endRead);



    // de aqui para arriba esta bien

    for (int k = 0; k < directionesDepth.size(); k++) {

        Estructura::Node dataAll;
        std::vector<Estructura::Pixel> puntos;
        
        Estructura es;

        PointsSelect pointSelect;
        
        
        //leer la imagen de profundidad
        collection.setImage(&depthImage);
        collection.readImage(height, width, directionesDepth[k], imageDepth);

        //leer la image de etiquetas
        collection.setImage(&lblImage);
        collection.readImage(height, width, directionesLabel[k], imageLabel);

        //std::cout << imageLabel << "\n";
        //para visualizar las imagenes que se estan cargando
        //es.seeImageDepth(height,width,imageDepth);
        //es.seeImageLabel(imageLabel);




        pointSelect.generatedPoints(type_Algorithm, puntos, NumPoints, height, width, NumTree);

        //llena los campos y carga al vector
        dataAll.imageDepth = imageDepth;
        dataAll.imageLabel = imageLabel;
        dataAll.points = puntos;
        dataAll.node = node;
        dataAll.tree = tree;
        structure.push_back(dataAll);
        
    }


}