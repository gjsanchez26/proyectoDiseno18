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
 * File:   CellBPC.h
 * Author: Sygram
 *
 * Created on May 5, 2018, 4:08 PM
 */

#ifndef CELLBPC_H
#define CELLBPC_H

#define BODY_PARTS_NUM 2

#include "Cell.h"

#include <vector>
#include <string>
#include <iostream>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/serialization/vector.hpp>



namespace rdf{

  namespace bpc {

    class Cell : public rdf::Cell{
    public:
      Cell();
      Cell(const Cell& orig);
      std::vector<float> left;
      std::vector<float> right;
      // Cell& Reduce(const Cell& other);
      void Reduce(const Cell& other);
      void SumByIndex(int toLeft, int index, float val);
      void SumByBodyPart(int toLeft, std::string bodyPart, float val);
      void InitValues(float leftVals, float rightVals);
      void AverageValues(int num);
      void Print();
      virtual ~Cell();
    private:
          /* --- Serialization --- */
          friend class boost::serialization::access;
          template<class Archive>
          void serialize(Archive & ar, const unsigned int version)
          {
            ar & left;
            ar & right;
          }
          /* ==== Serialization ==== */
      void Print(int i);
      int BodyPartToIndex(std::string bodyPart);

    };
  } /* bpc */
} /* rdf */

#endif /* CELLBPC_H */
