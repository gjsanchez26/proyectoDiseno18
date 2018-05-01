/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: will
 *
 * Created on 29 de abril de 2018, 09:56 PM
 */
#include <string>
#include <fstream>      // std::ifstream
#include <iostream>     // std::cout
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <stdio.h>
#include <omp.h>
#include <cmath>
#include "Image/ImageGetter.h"

/*struct dataInitial {
    int imgDepth[240][320];
    cv::Mat imageLabel;
};*/

int main(int argc, char** argv) {

    std::vector <ImageGetter::dataInitial> estructure;
    ImageGetter imageGet;
    imageGet.setVariables("shooton", 10, 19);
    imageGet.getStructure(estructure);
    ImageGetter::dataInitial temp;

    temp = estructure[9];



    /*for (int i = 0; i < 240; i++) {
        for (int j = 0; j < 320; j++) {
            cv::Scalar intensity = temp.imageDepth.at<unsigned short>(i, j);
            std::cout << intensity.val[0] << " ";
        }
        std::cout << "\n";
    }*/

    //cv::namedWindow( "Original image", CV_WINDOW_AUTOSIZE ); 
    //cv::imshow( "Original image", temp.imageLabel );
    //cv::waitKey(5000);



    //************************integrando openmp
    omp_set_num_threads(16);
    int id, np;
#pragma omp parallel private(id, np) 
    {
        np = omp_get_num_threads();
        id = omp_get_thread_num();
        printf("Hello from thread %d, out of %d threads\n", id, np);
    }
}


