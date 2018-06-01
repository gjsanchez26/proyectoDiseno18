/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageDispatcher.h
 * Author: gabo
 *
 * Created on May 22, 2018, 11:13 AM
 */
#include "NodeResource.h"
#include "Config.h"
#include "Resource.h"

#ifndef IMAGEDISPATCHER_H
#define IMAGEDISPATCHER_H

namespace rdf {
    /**'
        *  This class identify resources from all different nodes 
        *  and say how many images this node can load to the memory
        */
    class ImageDispatcher {
        
    public:
        ImageDispatcher();
        ImageDispatcher(const ImageDispatcher& orig);
        virtual ~ImageDispatcher();

        int analyzeResource(rdf::Resource &pResource); 
        void assignRanges(int pIntervals,bool pFlag);
        void addResource(rdf::Resource &pResource);
        void showRanges();

        std::vector<std::pair<int, int> > getImagesRanges() const {
            return _imagesRanges;
        }
        void setImagesRanges(std::vector<std::pair<int, int> > _imagesRanges) {
            this->_imagesRanges = _imagesRanges;
        }

    private:
        std::vector<std::pair<int,int>>     _imagesRanges;          /*!< Allow to save assigned image ranges */
        std::vector<rdf::Resource>          _resourceVector;
    };   
}

#endif /* IMAGEDISPATCHER_H */

