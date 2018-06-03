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
 * File:   NodeTraineeBPC.h
 * Author: Sygram
 *
 * Created on May 14, 2018, 2:20 AM
 */

#ifndef NODETRAINEEBPC_H
#define NODETRAINEEBPC_H

#include "MatrixBPC.h"
#include "NodeTrainee.h"

namespace rdf {

  namespace bpc {

    template <typename T>
    class NodeTrainee : public rdf::NodeTrainee {
    public:
      NodeTrainee();
      NodeTrainee(const NodeTrainee& orig);
      inline Matrix<T>& GetMatrix(){ return this->matrix_; };
      virtual ~NodeTrainee();
      Node * GetLeft(){};
      Node * GetRight(){};
      inline int GetParentId(){ return nodeId_ >> 1; }
      int GetLevel();
      inline void SetTreeId(int id){
        treeId_ = id;
      }
      inline void SetNodeId(int id){
        nodeId_ = id;
      }
      inline Matrix<T> GetNodeMatrix(){
        return matrix_;
      }
      /* Data members */
      int nodeId_;
      int treeId_;

    private:

      /* Data members */
      Matrix<T> matrix_;


    };

  } /* bpc */

} /* rdf */


#include "NodeTraineeBPC.tpp"

#endif /* NODETRAINEEBPC_H */
