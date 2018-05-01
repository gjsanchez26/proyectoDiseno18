/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageGetter.cpp
 * Author: will
 * 
 * Created on 29 de abril de 2018, 10:10 PM
 */

#include "ImageGetter.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>      // std::ifstream
#include <iostream>     // std::cout
#include <vector>
#include <stdio.h>

int width = 320;    //ancho de la imagen
int height = 240;   //alto de la imagen 
std::string pad = "/media/will/Data/Base_Disenio/pad.txt";  //direccion de la base de datos
std::string typeAlgorithm;   // tipo de algoritmos a futuro cargar varios tipos de imagenes
int starRead;    //inicio de la lectura de una imagen 
int endRead;     // fin de la lestura de la imagen 
 
/*Estructura para la primer imagen.*/
struct dataInitial {
    cv::Mat imageDepth;
    cv::Mat imageLabel;
};

ImageGetter::ImageGetter() {
}

ImageGetter::ImageGetter(const ImageGetter& orig) {
}

ImageGetter::~ImageGetter() {
}

void ImageGetter::readImages(int startLecture, int endLecture) {

    std::vector <std::string> image;
    int imgDepth [height][width];
    cv::Mat imageLbl(height, width, CV_8UC3);
    std::ifstream file;
    std::string line;

    std::string ruteDepth = "/media/will/Data/Base_Disenio/Data_0000001.dat";
    std::string ruteLbl = "/media/will/Data/Base_Disenio/Data_0000001.png";

    imageLbl = cv::imread(ruteLbl.c_str());
    //cv::namedWindow( "Original image", CV_WINDOW_AUTOSIZE ); 
    // cv::imshow( "Original image", imageLbl ); 

    file.open(ruteDepth.c_str(), std::ifstream::in);

    while (!file.eof()) {
        getline(file, line);
        std::string value;
        std::stringstream check1(line);
        while (getline(check1, value, ' ')) {
            image.push_back(value);

        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            imgDepth[i][j] = atoi(image[i * width + j].c_str());
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //std::cout << " " << imgDepth[i][j] << " ";
        }
        //std::cout << "\n";
    }


    file.close();
    //cv::waitKey(0);
}

/**
 * Funcion que retorna la estructura de la carga del rango de imagenes de la base de datos.
 * @param estructure
 */
void ImageGetter::getStructure(std::vector<dataInitial> &estructure) {
    //Variable con el fin de sacar la direccion de la ubicacion de las imagenes en la base de datos
    std::vector <std::string> directiones;
    //Variable con el fin de sacar la imagen de profundidad como un vector.
    std::vector <std::string> imageDepthTemp;

    //Variable para la lectura de la imagen de etiquetas
    cv::Mat imageLabel(height, width, CV_8UC3);
    
    //Variable temporal para crear la imagen de profundidad
    cv::Mat imageDepth;
    imageDepth = cv::Mat(height, width, CV_16UC1, cv::Scalar(0));
    int numLines = 0;

    //Leer las direciones con la cantidad de fotos
    readPad(directiones, numLines);

    //for para recorrer el rango de las imagenes que le corresponden al nodo del cluster
    for (int k = starRead; k <= endRead; k++) {
        //crear la estructura
        dataInitial data;
        //leer la imagen de profundidad
        readImageDepth(directiones[k].c_str(), imageDepthTemp);
        
        //for para asignar la lectura temporal de la imagen de profundidad a la 
        //imagen final de profundidad en la estructura
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cv::Scalar intensity; //defino un escalar 
                
                //asigno al escalar el valor de la imagen temporal.
                intensity.val[0] = (unsigned short)atoi(imageDepthTemp[i * width + j].c_str()); 
                imageDepth.at<unsigned short>(i, j) = intensity.val[0];
            }
        }
        
        //leer la imagen de etiquetas
        readImageLabel(directiones[k].c_str(), imageLabel);

        //Asigno a la estructura su respectiva imagen.
        data.imageLabel = imageLabel;
        data.imageDepth = imageDepth;
        
        //Agrego a la estrctura de datos.
        estructure.push_back(data);
    }

    /*for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cv::Scalar intensity = imageDepth.at<unsigned short>(i, j);
                std::cout << intensity.val[0] << " ";
            }
            std::cout << "\n";
        }*/

    //dataInitial temp;

    //temp = estructure[9];
    /*for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << inicial.imgDepth[i][j] << " ";
        }
        std::cout << "\n";
    }*/
    //cv::namedWindow( "Original image", CV_WINDOW_AUTOSIZE ); 
    //cv::imshow( "Original image", temp.imageLabel );
    //cv::waitKey(2000);
}


/**
 * Funcion con el fin de setiar las variables para el inicio de la lectura
 * y el fin de lectura de las imagenes que le corresponden a cada nodo del cluster 
 * @param type_Algorithm
 * @param star_Read
 * @param end_Read
 */
void ImageGetter::setVariables(std::string type_Algorithm, int star_Read, int end_Read) {

    typeAlgorithm = type_Algorithm;
    starRead = star_Read;
    endRead = end_Read;
}

/**
 * Funcion para leer el archivo que contiene la direccion de todas las imagenes en la base de datos 
 * @param directiones
 * @param cont
 */
void ImageGetter::readPad(std::vector<std::string>& directiones, int& cont) {
    std::ifstream file;
    std::string line;
    //int cont = 0;
    file.open(pad.c_str(), std::ifstream::in);
    //Leer el archivo hasta que termine.
    while (!file.eof()) {
        getline(file, line);//Lee la linea
        directiones.push_back(line); //agrega la linea al vector
        cont++;
    }
}

/**
 * Funcion para leer la imegen de profundidad temporalmente.
 * @param direction
 * @param image
 */
void ImageGetter::readImageDepth(std::string direction, std::vector<std::string>& image) {
    //std::vector <std::string> image;

    std::ifstream file;
    std::string line;

    std::string ruteDepth = direction + ".dat";
    file.open(ruteDepth.c_str(), std::ifstream::in);

    //Leer el archivo hasta que termine.
    while (!file.eof()) {
        getline(file, line);  //Lee la linea
        std::string value;
        std::stringstream check1(line);
        //While con el fin de dividir la linea por cada valor de pixel
        while (getline(check1, value, ' ')) {
            image.push_back(value); //ingresa el valor del pixel al vector temporal
        }
    }

    file.close();
}

/**
 * Funcion para la lectura de la imagen de etiquetas.
 * @param direction
 * @param imageLabel
 */
void ImageGetter::readImageLabel(std::string direction, cv::Mat& imageLabel) {

    cv::Mat imageLbl(height, width, CV_8UC3);
    std::string ruteLbl = direction + ".png"; //media/will/Data/Base_Disenio/Data_0000001.png";
    imageLbl = cv::imread(ruteLbl.c_str());
    imageLabel = imageLbl;
}