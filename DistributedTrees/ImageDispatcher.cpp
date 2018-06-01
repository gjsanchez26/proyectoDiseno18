/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageDispatcher.cpp
 * Author: gabo
 * 
 * Created on May 22, 2018, 11:13 AM
 */

#include <vector>

#include "ImageDispatcher.h"
#include "Resource.h"

rdf::ImageDispatcher::ImageDispatcher() {
}

rdf::ImageDispatcher::ImageDispatcher(const ImageDispatcher& orig) {
    _imagesRanges = orig._imagesRanges;

}
rdf::ImageDispatcher::~ImageDispatcher() {}

/**
 * This function intents analyze resource from each nodes in order to determinate how many images can charge
 * @param pResource : object that contains information about available memory in the node.
 * @return int : it is the number of images that can charge.
 */
int rdf::ImageDispatcher::analyzeResource(rdf::Resource &pResource) {
    // SOME KIND OF ANALYSIS OVER THE RESOURCE TO RETURN AN AMOUN NUMBER OF IMAGES
    
    int memAvaibale = pResource.getMemFree(); // KB
    int imageSize   = 10000;   // KB
    return memAvaibale / imageSize;

}

/**
 * This function assing the same number of images for each process and save them in a vector with a std::pair object
 * @param pIntervals : how many process or intervals.
 */
void rdf::ImageDispatcher::assignRanges(int pIntervals,bool pFlag) {
    if(pFlag){
            int multiple = TRAIN_IMAGES_AMOUNT/pIntervals;
            for(int i = 0 ; i < TRAIN_IMAGES_AMOUNT; i++){
                if(i%multiple == 0){
                    int a = i;
                    int b = i + multiple-1;
                    std::pair<int,int> range(a,b);
                    _imagesRanges.push_back(range);
                }   
            }
    }
    
    else {
        int imageSum = 0;
        for(int i = 0; i< _resourceVector.size(); i++){
            Resource temp = _resourceVector[i];
            
            if(i==0){
                int imageAmount = analyzeResource(temp);
                int    a = i;
                int    b = i + imageAmount - 1;
                imageSum = imageAmount  + imageAmount;
                std::pair<int,int> range(a,b);
                _imagesRanges.push_back(range);
            }
            else {
                int imageAmount = analyzeResource(temp);
                std::pair<int,int> lastRange;
                lastRange = _imagesRanges.back();
                int a = lastRange.second+1;
                int b = lastRange.second + imageAmount-1;
                imageSum = imageAmount  + imageAmount;
                std::pair<int,int> range(a,b);
                _imagesRanges.push_back(range);
                
            }
            
        } 
    }
}

void rdf::ImageDispatcher::showRanges() {
    for(int i = 0 ; i < _imagesRanges.size(); i++){
        std::cout << "Node " << i+1 << ": [" <<_imagesRanges[i].first <<"," << _imagesRanges[i].second << "] \n";
    }
}

void rdf::ImageDispatcher::addResource(rdf::Resource& pResource) {
    _resourceVector.push_back(pResource);
    

}




