/* 
 * File:   DepthImage.h
 * Authors: 
 * Gabriel Sanchez
 * Alejandro Gonzalez
 * Wilberth Varela
 *
 */

#ifndef DEPTHIMAGE_H
#define DEPTHIMAGE_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "StrategyImage.h"

namespace rdf {

    /**
     * This class works to read depth image 
     */
    class DepthImage : public StrategyImage {
    public:
        DepthImage();
        DepthImage(const DepthImage& orig);
        virtual ~DepthImage();
        virtual void readImage(int height, int width, std::string direction, cv::Mat& image);
    private:

    };
}

#endif /* DEPTHIMAGE_H */
