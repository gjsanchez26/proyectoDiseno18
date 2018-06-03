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
 * File:   ImageOperations.cpp
 * Author: Sygram
 *
 * Created on May 22, 2018, 12:17 AM
 */

#include "ImageOperations.h"

using namespace rdf;

ImageOperations::ImageOperations() {
}

ImageOperations::ImageOperations(const ImageOperations& orig) {
}


void ImageOperations::SetImagesDistribution(
  std::vector<Estructura::Node>& imagesSet,
  int percentage,
  int numTrees
){
    int total = imagesSet.size();
    int percentageNum = (percentage / 100) * total;
    for (int i = 0; i < numTrees; i++) {
      AssignTreeFlagsToImagesSet(imagesSet, percentageNum, i, total);
    }
}

void ImageOperations::AssignTreeFlagsToImagesSet(
  std::vector<Estructura::Node>& imagesSet,
  int percentageNum,
  int treeNum,
  int totalSize
){
    int count = 0;
    int randomNum = 0;
    int treeFlag = 0;
    std::uniform_int_distribution<int> int_dist(0, totalSize - 1);
    while (count < percentageNum) {
      randomNum = int_dist(mt_);
      treeFlag = imagesSet[randomNum].treesAvailability[treeNum];
      if (treeFlag == 0){
        imagesSet[randomNum].treesAvailability[treeNum] = 1;
        count++;
      }
    }
  }





ImageOperations::~ImageOperations() {
}



std::mt19937 ImageOperations::InitRandomSeed() {
    std::random_device rd;
    std::mt19937 mt(rd());
    return mt;
}

std::mt19937 ImageOperations::mt_ = ImageOperations::InitRandomSeed();

