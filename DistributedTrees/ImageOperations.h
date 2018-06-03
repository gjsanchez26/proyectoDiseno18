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
 * File:   ImageOperations.h
 * Author: Sygram
 *
 * Created on May 22, 2018, 12:17 AM
 */

#ifndef IMAGEOPERATIONS_H
#define IMAGEOPERATIONS_H

#include <random>
#include "Estructura.h"


namespace rdf {

  class ImageOperations {
  public:
    ImageOperations();
    ImageOperations(const ImageOperations& orig);
    void SetImagesDistribution(std::vector<Estructura::Node>&, int, int);
    virtual ~ImageOperations();
  private:
    void AssignTreeFlagsToImagesSet(std::vector<Estructura::Node>&, int, int, int);
    static std::mt19937 InitRandomSeed();
    static std::mt19937 mt_; //MersenneTwister pseudo-random engine

  };

} /* rdf */

#endif /* IMAGEOPERATIONS_H */
