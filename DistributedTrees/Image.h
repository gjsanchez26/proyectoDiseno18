/* 
 * File:   Image.h
 * Authors: 
 * Gabriel Sanchez
 * Alejandro Gonzalez
 * Wilberth Varela
 *
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include "Estructura.h"
#include "Collection.h"
#include "LabelImage.h"
#include "DepthImage.h"

namespace rdf {

    /*
     * This class works to manager images to diferents algorithms
     */
    class Image {
    public:
        Image();
        Image(const Image& orig);
        virtual ~Image();
        void getStructura(std::vector<rdf::Estructura::Node>& structure, rdf::Estructura::DataMaster dataMaster);
    private:
        void generatedStructureShotton(std::vector<rdf::Estructura::Node>& structure,
                std::string type_Algorithm, int NumPoints, int height, int width,
                int NumTree, std::string pathDepth, std::string pathlabel,
                int startRead, int endRead, int tree, int node);

    };
}
#endif /* IMAGE_H */

