/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resource.h
 * Author: will
 *
 * Created on 31 de mayo de 2018, 09:13 AM
 */

#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>     // std::cout
#include <boost/serialization/access.hpp>

namespace rdf {
    

    class Resource {
        private:
            friend class boost::serialization::access;
                template<class Archive>
                void serialize(Archive & ar, const unsigned int version)
                {
                    ar & MemTotal;
                    ar & MemFree;
                    ar & CPUs;
                    ar & Frequency;
                    ar & rank;
            }
            int MemTotal;
            int MemFree;
            int CPUs;
            int Frequency; //la velocidad es de kB
            int rank;
            
        public:
            Resource();
            Resource(const Resource& orig);
            
            virtual ~Resource();
            void displayResource();

            int getCPUs() const {
                return CPUs;
            }

            void setCPUs(int CPUs) {
                this->CPUs = CPUs;
            }

            int getFrequency() const {
                return Frequency;
            }

            void setFrequency(int Frequency) {
                this->Frequency = Frequency;
            }

            int getMemFree() const {
                return MemFree;
            }

            void setMemFree(int MemFree) {
                this->MemFree = MemFree;
            }

            int getMemTotal() const {
                return MemTotal;
            }

            void setMemTotal(int MemTotal) {
                this->MemTotal = MemTotal;
            }


        

    };
}
#endif /* RESOURCE_H */

