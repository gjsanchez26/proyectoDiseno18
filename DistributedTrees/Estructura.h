
/* 
 * File:   Estructura.h
 * Authors: 
 * Gabriel Sanchez
 * Alejandro Gonzalez
 * Wilberth Varela
 *
 */

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>

namespace rdf {

    /*
     * This class works to create the structure of diferent images 
     */
    class Estructura {
    public:
        Estructura();
        Estructura(const Estructura& orig);
        virtual ~Estructura();

        struct Pixel {
            cv::Point point;
            std::vector<int> ubicacion;
        } pixel;

        struct Node {
            cv::Mat imageDepth;
            cv::Mat imageLabel;
            std::vector<Estructura::Pixel> points;
            std::vector<int> treesAvailability;
            int tree;
            int node;

            void getTotalSize(int& valor) {
                valor = sizeof (imageDepth) + sizeof (imageLabel) + sizeof (points) + sizeof (tree) + sizeof (node);
            }
        } node;

        struct DataMaster {
            std::string type_Algorithm;
            int NumPoints;
            int height;
            int width;
            int NumTree;
            int startRead;
            int endRead;
            int tree;
            int node;
        } dataMaster;

        void seeImageDepth(int height, int width, cv::Mat imageDepth);
        void seeImageLabel(cv::Mat& imageLabel);

    private:


    };
}

#endif /* ESTRUCTURA_H */

