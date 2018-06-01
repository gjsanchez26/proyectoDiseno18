/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collection.h
 * Author: will
 *
 * Created on 1 de mayo de 2018, 09:06 PM
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include <string>
#include "StrategyImage.h"


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

#endif /* COLLECTION_H */

