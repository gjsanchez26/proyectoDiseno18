/*
 * Copyright (C) 2018 Sygram
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   MatrixBPCFeatures.h
 * Author: Sygram
 *
 * Created on May 6, 2018, 3:23 PM
 */

#ifndef MATRIXBPCFEATURES_H
#define MATRIXBPCFEATURES_H

#include <vector>
#include <utility>
#include <random>
#include <assert.h>
#include <iostream>

#include <fstream>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>


template <typename T>
using Features =  std::pair<T,T>;
// using Features =  std::vector<std::pair<T,T>>;

template <typename T>
class MatrixBPCFeatures {
public:
    MatrixBPCFeatures();
    MatrixBPCFeatures(int fn, T fh, T fl, int tn, T th, T tl);
    MatrixBPCFeatures(const MatrixBPCFeatures& orig);
    void SetNumThresholds(int); //size of thresholds vector
    void SetNumFeatures(int); //size of features vector
    void SetThresholdsNumRange(T h, T l);
    void SetFeaturesNumRange(T h, T l);
    void GenerateThresholdsVector();
    void GenerateFeaturesVector();
    void GenerateVectors();
    void Print();
    virtual ~MatrixBPCFeatures();

    /* Data members */
    std::vector<T> thresholds_;
    std::vector<Features<T>> features_;
    int numFeatures_;     // ROWS / X-Axis
    int numThresholds_;   // COLS / Y-Axis
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & thresholds_;
        ar & features_;
        ar & numFeatures_;
        ar & numThresholds_;
        ar & thresholdsLowRange_;
        ar & thresholdsHighRange_;
        ar & featuresLowRange_;
        ar & featuresHighRange_;
    }
  T thresholdsLowRange_;
  T thresholdsHighRange_;
  T featuresLowRange_;
  T featuresHighRange_;
  static std::mt19937 mt_; //Mersenne twister pseudo-random engine
};

#endif /* MATRIXBPCFEATURES_H */
