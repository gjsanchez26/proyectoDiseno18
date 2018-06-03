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
 * File:   MatrixBPC.cpp
 * Author: Sygram
 *
 * Created on May 5, 2018, 4:08 PM
 */

#include "MatrixBPC.h"
#include "CellBPC.h"

namespace rdf{

  namespace bpc {

    template <typename T>
    Matrix<T>::Matrix() {
        this->rows_ = 0;
        this->cols_ = 0;
    }

    template <typename T>
    Matrix<T>::Matrix(const FeaturesMat& mat) {
      featuresMatrix_ = mat;
      rows_ = (int) mat.numFeatures_;
      cols_ = (int) mat.numThresholds_;
      AllocateCells();
    }

    template <typename T>
    void Matrix<T>::AddFeaturesMat(const FeaturesMat &mat){
      featuresMatrix_ = mat;
      rows_ = mat.numFeatures_;
      cols_ = mat.numThresholds_;
      AllocateCells();
    }



    template <typename T>
    void Matrix<T>::AllocateCells() {
       cells_ = (T*) malloc(sizeof(*cells_) * rows_ * cols_);
       for (size_t i = 0; i < rows_; i++) {
         for (size_t j = 0; j < cols_; j++) {
           Cell cell;
           cells_[i * rows_ + j] = cell;
         }
       }
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix& orig) {
        AddFeaturesMat(orig.featuresMatrix_);
        for (size_t i = 0; i < rows_; i++) {
          for (size_t j = 0; j < cols_; j++) {
              cells_[i * rows_ + j] = orig.cells_[i * rows_ + j];
          }
        }
    }


    template <typename T>
    void Matrix<T>::Reduce(Matrix& other) {
      Cell otherCell;
      for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
          otherCell = other(i,j);
          cells_[i * rows_ + j].Reduce(otherCell);
        }
      }
    }

    template <typename T>
    void Matrix<T>::Average(int average) {
      for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
          cells_[i * rows_ + j].AverageValues(average);
        }
      }
    }

    template <typename T>
    void Matrix<T>::EvaluatePointInMatrix(int point){
      float result = 0;
      for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
          result = CalculateFeatureResponse(point, i, j);
        }
      }
    }



template <typename T>     //TODO - Real implementation
float Matrix<T>::CalculateFeatureResponse(int pointValue, int featureIndex, int thresholdIndex){
  Features currFeatures = featuresMatrix_.features_[featureIndex];
  int currThreshold = featuresMatrix_.thresholds_[thresholdIndex];
  float x1 = currFeatures.GetFeature1().x;
  float x2 = currFeatures.GetFeature2().x;
  float y1 = currFeatures.GetFeature1().y;
  float y2 = currFeatures.GetFeature2().y;
  // std::uniform_int_distribution<int> probability_50(0,1);
  int isTrue = 1; //TODO IMPLEMENT PROBABILITY
  float result;
  if (isTrue){
      result = static_cast<float> ((pointValue/(x1+y1)) + (pointValue/(x2+y2)));
  } else{
      result = static_cast<float> ((pointValue/(x1+y1)));
  }
  return result;

}

    template <typename T>
    void Matrix<T>::Print() {
      for (size_t i = 0; i < rows_; i++) {
        for (size_t j = 0; j < cols_; j++) {
          cells_[i * rows_ + j].Print();
        }
      }
    }


    template <typename T>
    Matrix<T>::~Matrix() {
    }


  } /* bpc */


} /* rdf */

//
//template <typename T>
//void MatrixBPC<T>::train() {
//    assert(cellSize_ > 0);
//    //    int nprocs = 2 * omp_get_num_procs();
//    //    omp_set_num_threads(8);
//    int numFeatures = featuresMatrix_.numFeatures_;
//    int numThresholds = featuresMatrix_.numThresholds_;
//#pragma omp parallel
//        {
//#pragma  omp for
//    for (size_t x = 0; x < numFeatures; x++) {
//        Features<T> features = featuresMatrix_.features_[x];
//        T feature1 = features.first;
//        T feature2 = features.second;
//
//
//            for (size_t y = 0; y < numThresholds; y++) {
//                T threshold = featuresMatrix_.thresholds_[y];
//                T newNum = (feature1 + feature2) / 2;
//                CellBPC<T> newCell;
//                if (newNum >= threshold) {
//                    // std::cerr << "index[" << x <<"][" << y <<"]" << "soy MAYOR" << std::endl;
//                    newCell.left[5] += 1;
//                    cells_[x * cellSize_ + y] = newCell;
//                } else {
//                    newCell.right[7] += 1;
//                    cells_[x * cellSize_ + y] = newCell;
//                    // std::cerr << "index[" << x <<"][" << y <<"]" << "soy menor" << std::endl;
//                }
//            }
//        }
//    }
//}
//
