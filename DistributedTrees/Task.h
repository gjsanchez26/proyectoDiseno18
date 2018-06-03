/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Task.h
 * Author: gabo
 *
 * Created on May 17, 2018, 4:09 PM
 */
#include <iostream>
#include <boost/serialization/access.hpp>
#include "FeaturesMat.h"
#include "Config.h"

#ifndef TASK_H
#define TASK_H
namespace rdf {
    /** This class encapsulate a task in the process of training trees
        */
    class Task {
        private:
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive & ar, const unsigned int version)
            {
                ar & _rank;
                ar & _tree;
                ar & _node;
                ar & _status;
                ar & _featureMatrix;
            }
            int     _rank;                              /*!< Number of process */
            int     _tree;                              /*!< Tree Number */
            int     _node;                              /*!< Node Number*/
            bool    _status;                            /*!< Number of process */
            rdf::bpc::FeaturesMat _featureMatrix;       /*!< Feature Matrix*/

        public:
            Task();
            Task( int _rank,  int _tree,  int _node, bool _status);
            Task(const Task& orig);
            virtual ~Task();
            
            
            //GETTERS AND SETTERS MOST IMPORTANT VARAIBLES

            void showTask();
            void reduce(Task &pTask1);

            int getNode() const {
                return _node;
            }
            void setNode(int _node) {
                this->_node = _node;
            }

            int getRank() const {
                return _rank;
            }

            void setRank(int _rank) {
                this->_rank = _rank;
            }

            bool isStatus() const {
                return _status;
            }

            void setStatus(bool _status) {
                this->_status = _status;
            }

            int getTree() const {
                return _tree;
            }

            void setTree(int _tree) {
                this->_tree = _tree;
            }

            rdf::bpc::FeaturesMat getFeatureMatrix() const {
                return _featureMatrix;
            }

            void setFeatureMatrix(rdf::bpc::FeaturesMat _featureMatrix) {
                this->_featureMatrix = _featureMatrix;
            }
            bool operator< (const Task& pTask) const
            {
                if(pTask._rank < this->_rank)
                    return true;
            }
            bool operator== (const Task& pTask) const
            {
                if(pTask._node == this->_node && pTask._tree == this->_tree )
                    return true;
            }
    };

}

#endif /* TASK_H */

