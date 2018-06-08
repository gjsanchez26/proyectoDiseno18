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
 * File:   TrainerBPC.cpp
 * Author: Sygram
 *
 * Created on May 14, 2018, 7:16 PM
 */

#include "TrainerBPC.h"
#include <iostream>

using namespace rdf::bpc;

Trainer::Trainer() {
   
}

Trainer::Trainer(const Trainer& orig) {
}


void Trainer::Train(Node * node, std::vector<Estructura::Node>& imagesTrainingSet, rdf::NodeResult& nodeResult){
  std::cout<< "Trainning...\n";
  NodeTrainee<Cell>* nodeTrainee = static_cast<NodeTrainee<Cell>* > (node);
  int nodeId =  nodeTrainee->nodeId_;
  int treeId =  nodeTrainee->treeId_;
  int nodeInTree, pointsSize, treeFlag;
  std::vector<Estructura::Pixel> *points = nullptr;
  std::cout << "nodeId: "<< nodeId << "\ttreeId: "<< treeId << '\n';
  int n = 0;
  for (auto &image : imagesTrainingSet) { // for every image
    // treeFlag = image.treesAvailability[treeId];
     if (treeFlag == 0) continue; //this means image doesn't belong to given tree
      points = &image.points;
      for (auto const &point : *points) {           // for every point
        // std::cout << "gg!" << ++n << '\n';
            nodeInTree = point.ubicacion[treeId];
            cv::Point p = point.point;
            
            /*if (nodeInTree == nodeId){
               // nodeTrainee->GetMatrix().EvaluatePointInMatrix(point); //for every feature and threshold
            }*/
          //std::cout << "Punto ("<< p.x << "," << p.y <<") \n"; 
        }
  }
//  nodeTrainee->GetMatrix().Print();
   nodeResult.setMatrixResults(nodeTrainee->GetMatrix());
  //nodeResult.getMatrixResults().Print();
  
}

Trainer::~Trainer() {
}
