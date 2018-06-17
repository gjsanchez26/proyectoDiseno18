/* 
 * File:   Collection.h
 * Authors: 
 * Gabriel Sanchez
 * Alejandro Gonzalez
 * Wilberth Varela
 *
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>
#include "StrategyImage.h"

namespace rdf {

    /**
     *This class works for implement the abstraction of diferent images  
     * 
     */
    class Collection {
    public:
        Collection();
        Collection(const Collection& orig);
        virtual ~Collection();
        void setImage(StrategyImage* TypeImage);
        void readImage(int height, int width, std::string direction, cv::Mat& image);
    private:
        StrategyImage* stImage;

    };

}
#endif /* COLLECTION_H */
