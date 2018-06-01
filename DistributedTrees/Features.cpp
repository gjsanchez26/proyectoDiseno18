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
 * File:   Features.cpp
 * Author: Sygram
 *
 * Created on May 8, 2018, 10:43 PM
 */

#include "Features.h"


using namespace rdf::bpc;

Features::Features() {
  feature1_.x = 0;
  feature1_.y = 0;
  feature2_.x = 0;
  feature2_.y = 0;
}

Features::Features(float feat1_x, float feat1_y, float feat2_x, float feat2_y) {
  feature1_.x = feat1_x;
  feature1_.y = feat1_y;
  feature2_.x = feat2_x;
  feature2_.y = feat2_y;
}


Feature Features::SetFeature1(float x, float y){
  feature1_.x = x;
  feature1_.y = y;
  return feature1_;
}

Feature Features::SetFeature2(float x, float y){
  feature2_.x = x;
  feature2_.y = y;
  return feature2_;
}

Feature Features::GetFeature1(){
  return feature1_;
}

Feature Features::GetFeature2(){
  return feature2_;
}

Features::Features(const Features& orig) {
  feature1_ = orig.feature1_;
  feature2_ = orig.feature2_;
}

Features::~Features() {
}
