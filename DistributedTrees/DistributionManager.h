/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DistributionManager.h
 * Author: gabo
 *
 * Created on May 22, 2018, 8:30 AM
 */
#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Task.h"
#include <tuple>
#include <stdlib.h>
#include <unistd.h>
#include "ImageDispatcher.h"
#include "ForestManager.h"
#include "NodeResult.h"
#include "ImageManager.h"
#include "BestFeatureMsg.h"
#include "Scheduler.h"




#ifndef DISTRIBUTIONMANAGER_H
#define DISTRIBUTIONMANAGER_H
namespace mpi = boost::mpi;

namespace rdf {
    /**
        *  Class that works on distribute all messages within MPI.BOOST
        *  
        * 
        */
    class DistributionManager {

    private:
        mpi::environment                        _env;                   /*!< Mpi variable to manage the enviroment */
        mpi::communicator                   _world;                 /*!< Mpi variable to identify the world of process */
        //std::vector<std::string>                          _clusterResourses;      /*< Mpi variable to manage the enviroment */
        std::vector<std::pair<int,int>>     _imageRanges;           /*!< Vector that includes ranges for each process */
        //std::vector<Task>                                        _clusterResults;                                            
        pair<int,int>                       _myRange;               /*!< Pair that allows ideantify the range  by the process */   
        ImageManager                        _myImageManager;        /*!< It allows to get images from memory in the range*/  
        rdf::ForestManager                  _forestManager;  
        rdf::ImageDispatcher                _imageDistpatcher; 
        Scheduler                           _scheduler;
        
            
    public:
        DistributionManager();
        DistributionManager(const DistributionManager& orig);
        virtual ~DistributionManager();
            
        /**
                *  ALL THIS FUNCTIONS ARE FOR SENDING MESSAGES BETWEEN SLAVE NODES AND MASTER NODE
                *  All documentation about it is in  DistributionManager.cpp
                */
        void waitingResults();
        void sendingResults();
        
        void transferResources();
        void transferRanges();
        
        void transferNodes(Task &pTask);
        void transferResults();
        
        void transferBeacon();

        void transferTrainStart(ForestManager &pForest);
        
        void transferBestFeature(rdf::bpc::BestFeatureMsg pFeature); 
        void transferFinish();
        
        
        /**
                *  GETTERS AND SETTERS FOR MAIN VARIABLES
                */

        std::vector<std::pair<int, int> > getImageRanges() const {
            return _imageRanges;
        }

        void setImageRanges(std::vector<std::pair<int, int> > _imageRanges) {
            this->_imageRanges = _imageRanges;
        }
        ImageManager getMyImageManager() const {
            return _myImageManager;
        }

        void setMyImageManager(ImageManager _myImageManager) {
            this->_myImageManager = _myImageManager;
        }

        pair<int, int> getMyRange() const {
            return _myRange;
        }

        void setMyRange(pair<int, int> _myRange) {
            this->_myRange = _myRange;
        }
    };
}
#endif /* DISTRIBUTIONMANAGER_H */

