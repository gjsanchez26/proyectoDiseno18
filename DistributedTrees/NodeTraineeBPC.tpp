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
 * File:   NodeTraineeBPC.cpp
 * Author: Sygram
 *
 * Created on May 14, 2018, 2:20 AM
 */

#include "NodeTraineeBPC.h"

using namespace rdf::bpc;


template <typename T>
NodeTrainee<T>::NodeTrainee() {
}

template <typename T>
NodeTrainee<T>::NodeTrainee(const NodeTrainee& orig) {
}

template <typename T>
int NodeTrainee<T>::GetLevel() {
  int id = nodeId_;
  int count = 1;
  while ( (id >>= 1) > 0) count++;
  return count;
}

template <typename T>
NodeTrainee<T>::~NodeTrainee() {
}
