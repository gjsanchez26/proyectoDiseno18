//* 
 * File:   LabelImage.h
 * Authors: 
 * Gabriel Sanchez
 * Alejandro Gonzalez
 * Wilberth Varela
 *
 */

#ifndef LABELIMAGE_H
#define LABELIMAGE_H

#include <iostream>
#include "StrategyImage.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace rdf {

    /*
     * This class load label image 
     */
    class LabelImage : public StrategyImage {
    public:
        LabelImage();
        LabelImage(const LabelImage& orig);
        virtual ~LabelImage();
        virtual void readImage(int height, int width, std::string direction, cv::Mat& image);


    private:

    };
}

#endif /* LABELIMAGE_H */



