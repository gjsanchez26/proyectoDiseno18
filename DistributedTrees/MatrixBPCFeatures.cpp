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
 * File:   MatrixBPCFeatures.cpp
 * Author: Sygram
 *
 * Created on May 6, 2018, 3:23 PM
 */

#include "MatrixBPCFeatures.h"

template <typename T>
MatrixBPCFeatures<T>::MatrixBPCFeatures() {
  numFeatures_ = 0;
  numThresholds_ = 0;
  featuresHighRange_ = 0;
  featuresLowRange_ = 0;
  thresholdsHighRange_ =  0;
  thresholdsLowRange_ = 0;
}

template <typename T>
MatrixBPCFeatures<T>::MatrixBPCFeatures(int numFeatures, T featuresHigh,
  T featuresLow, int numThresholds, T thresholdsHigh, T thresholdsLow) {
    numFeatures_ = numFeatures;
    numThresholds_ = numThresholds;
    featuresHighRange_ = featuresHigh;
    featuresLowRange_ = featuresLow;
    thresholdsHighRange_ =  thresholdsHigh;
    thresholdsLowRange_ = thresholdsLow;
}


template <typename T>
MatrixBPCFeatures<T>::MatrixBPCFeatures(const MatrixBPCFeatures& orig) {
}

template <typename T>
void MatrixBPCFeatures<T>::SetNumThresholds(int numThresholds){
  numThresholds_ = numThresholds;
}

template <typename T>
void MatrixBPCFeatures<T>::SetNumFeatures(int numFeatures){
  numFeatures_ = numFeatures;
}

template <typename T>
void MatrixBPCFeatures<T>::SetThresholdsNumRange(T high, T low){
  thresholdsHighRange_ = high;
  thresholdsLowRange_ = low;
}


template <typename T>
void MatrixBPCFeatures<T>::SetFeaturesNumRange(T high, T low) {
  featuresHighRange_ = high;
    featuresLowRange_ = low;
}

template <typename T>
void MatrixBPCFeatures<T>::GenerateThresholdsVector() {
  assert(numThresholds_ > 0);
    assert(thresholdsHighRange_ > thresholdsLowRange_);
    std::uniform_real_distribution<T> threshold_dist(thresholdsLowRange_, thresholdsHighRange_);
    for (size_t i = 0; i < numThresholds_; i++) {
        T randomThreshold = threshold_dist(mt_);
        thresholds_.push_back(randomThreshold);
        // std::cout << "i-" << i << " T: " << thresholds_[i] << std::endl;
    }
}


template <typename T>
void MatrixBPCFeatures<T>::GenerateFeaturesVector() {
    assert(numFeatures_ > 0);
    assert(featuresHighRange_ > featuresLowRange_);
    std::uniform_real_distribution<T> features_dist(featuresLowRange_, featuresHighRange_);
    for (size_t i = 0; i < numFeatures_; i++) {
        T randomFeature1 = features_dist(mt_);
        T randomFeature2 = features_dist(mt_);
        Features<T> featuresPair = std::make_pair(randomFeature1, randomFeature2);
        // std::cout << "i-" << i << " F1: " << randomFeature1 << std::endl;
        // std::cout << "i-" << i << " F2: " << randomFeature2 << std::endl;
        features_.push_back(featuresPair);
    }
}

template <typename T>
void MatrixBPCFeatures<T>::GenerateVectors(){
  GenerateThresholdsVector();
  GenerateFeaturesVector();
}

template <typename T>
void MatrixBPCFeatures<T>::Print(){
  for (int i = 0;  i < thresholds_.size() ; i++) {
    // std::cerr << "Printing T[" << i << "]: " << thresholds_.at(i) << std::endl;
  }
}


template <typename T>
MatrixBPCFeatures<T>::~MatrixBPCFeatures() {
}

std::mt19937 init2() {
    std::random_device rd;
    std::mt19937 mt(rd());
    return mt;
}

template <typename T>
std::mt19937 MatrixBPCFeatures<T>::mt_ = init2();


template class MatrixBPCFeatures<float>;
template class MatrixBPCFeatures<double>;
template class MatrixBPCFeatures<long double>;
