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
 * File:   Features.h
 * Author: Sygram
 *
 * Created on May 8, 2018, 10:43 PM
 */

#ifndef FEATURES_H
#define FEATURES_H

#include <opencv2/core/core.hpp>
#include <opencv2/core/types_c.h>
#include <utility>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


namespace rdf {
    namespace bpc {

        typedef CvPoint2D32f Feature;

        class Features {
        public:
            Features();
            Features(float, float, float, float);
            Features(const Features& orig);
            virtual ~Features();
            std::pair<Feature, Feature> GetFeatures(){}; //TODO

            /* Data members */
            Feature feature1_;
            Feature feature2_;
            Feature SetFeature1(float x, float y);
            Feature SetFeature2(float x, float y);
            Feature GetFeature1();
            Feature GetFeature2();
        private:

          /* --- Serialization --- */
          friend class boost::serialization::access;
          template<class Archive>
          void serialize(Archive & ar, const unsigned int version)
          {
            ar & feature1_.x;
            ar & feature1_.y;
            ar & feature2_.x;
            ar & feature2_.y;
          }
          /* ==== Serialization ==== */

        };

    } /* bpc */
} /* rdf */

#endif /* FEATURES_H */
