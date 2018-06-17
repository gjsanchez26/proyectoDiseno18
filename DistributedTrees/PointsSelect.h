/* 
 * File:   PointsSelect.h
 * Authors: 
 * Gabriel Sanchez
 * Alejandro Gonzalez
 * Wilberth Varela
 *
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

namespace rdf {

    /*
     * This class select points to each image
     */
    class PointsSelect {
    public:
        PointsSelect();
        PointsSelect(const PointsSelect& orig);
        virtual ~PointsSelect();
        void generatedPoints(std::string type_Algorithm, std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree);

    private:
        void generatShoton(std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree);

    };
}

#endif /* POINTSSELECT_H */

