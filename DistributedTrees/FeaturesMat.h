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
 * File:   FeaturesMat.h
 * Author: Sygram
 *
 * Created on May 8, 2018, 11:45 PM
 */

#ifndef FEATURESMAT_H
#define FEATURESMAT_H

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

#include "Features.h"



namespace rdf {
  namespace bpc {

    template <class T>
    class Matrix;

    class FeaturesMat {
    public:
      FeaturesMat();
      FeaturesMat(const FeaturesMat& orig);
      FeaturesMat(int fn, float fh, float fl, int tn, float th, float tl);
      void SetMatrixSize(int x, int y); // x = Features // y = Thresholds
      void SetNumThresholds(int); //size of thresholds vector
      void SetNumFeatures(int); //size of features vector
      void SetThresholdsNumRange(float high, float low);
      void SetFeaturesNumRange(float high, float low);
      void GenerateVectors();
      // float EvaluatePoint(int);
      void Print();
      virtual ~FeaturesMat();
      
      inline float GetThresholdAt(int x){
        return thresholds_[x];
      }
      inline Features GetFeaturesAt(int x){
        return features_[x];
      }

    private:
      template <class T> friend class Matrix;
      friend class boost::serialization::access;
      void GenerateThresholdsVector();
      void GenerateFeaturesVector();
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

            /* Data members */
            std::vector<float> thresholds_;
            std::vector<Features> features_;
            int numFeatures_;     // ROWS / X-Axis
            int numThresholds_;   // COLS / Y-Axis

      float thresholdsLowRange_;
      float thresholdsHighRange_;
      float featuresLowRange_;
      float featuresHighRange_;
      static std::mt19937 mt_; //Mersenne twister pseudo-random engine
    };

  } /* bpc */
} /* rdf */

#endif /* FEATURESMAT_H */
