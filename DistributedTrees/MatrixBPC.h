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
 * File:   MatrixBPC.h
 * Author: Sygram
 *
 * Created on May 5, 2018, 4:08 PM
 */

#ifndef MATRIXBPC_H
#define MATRIXBPC_H

#include "Matrix.h"
#include "FeaturesMat.h"
#include <stdlib.h>
#include <omp.h>
#include "CellBPC.h"

#include <boost/serialization/split_member.hpp>


namespace rdf {
  namespace bpc {

    //TODO - Work on better structure/interface for this class

    template <typename T>
    class Matrix: public rdf::Matrix<T> {
    public:
         Matrix();
         Matrix(const FeaturesMat &);
         Matrix(const Matrix& orig);
        virtual ~Matrix();
        void AddFeaturesMat(const FeaturesMat &mat);
         void AllocateCells();
      //    void train();
         void Reduce(Matrix &other);
         void Average(int average);
         void Print();
         void EvaluatePointInMatrix(int point);
         float CalculateFeatureResponse(int, int, int);
         bool EvaluateFeatureResponseForThreshold(float, int);
         T operator ()(int i, int j){
             return cells_[i * this->rows_ + j];
         }
        std::pair<int,int> FindBestPair(){
           return std::make_pair(2,3);
         }

         /* Data members */

         FeaturesMat featuresMatrix_;

    private:
               int rows_;
               int cols_;
               T* cells_;

            friend class boost::serialization::access;

            template<class Archive>
   void save(Archive & ar, const unsigned int version) const
   {
     ar & featuresMatrix_;
     ar & rows_;
     ar & cols_;
     for (size_t i = 0; i < rows_; i++) {
       for (size_t j = 0; j < cols_; j++) {
         ar & cells_[i * rows_ + j];
       }
     }
   }
   template<class Archive>
      void load(Archive & ar, const unsigned int version)
      {
        ar & featuresMatrix_;
        ar & rows_;
        ar & cols_;
        AllocateCells();
        for (size_t i = 0; i < rows_; i++) {
          for (size_t j = 0; j < cols_; j++) {
            ar & cells_[i * rows_ + j];
          }
        }
      }

      BOOST_SERIALIZATION_SPLIT_MEMBER()

    };

  } /* bpc */
} /* rdf */


#include "MatrixBPC.tpp"

#endif /* MATRIXBPC_H */
