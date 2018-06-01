/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeResult.h
 * Author: gabo
 *
 * Created on May 22, 2018, 3:08 PM
 */
#include <vector>
#include <iostream>
#include <boost/serialization/access.hpp>
#include "Task.h" 
#include "MatrixBPC.h"


#ifndef NODERESULT_H
#define NODERESULT_H

namespace rdf {
    
    class NodeResult {
        
        /** This class allows to manage information about results of training
                */

        private:
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive & ar, const unsigned int version)
            {
                ar & _resultSize;
                ar & _status;
                ar & _task;
                ar & _matrixResults;
            }
            int                                 _resultSize = 0;   /*!< To identify the number of results*/
            bool                                _status;           /*!< To know when all matix had been reduced*/
            rdf::Task                           _task;             /*!< To know which task produce the result*/
            rdf::bpc::Matrix<rdf::bpc::Cell>    _matrixResults;




        public:
            NodeResult();
            NodeResult(const NodeResult& orig);
            virtual ~NodeResult();
            void reduce(NodeResult &Result);
            
            
            // GETTERS AND SETTERS MOST IMPORTANT VARIABLES

            rdf::bpc::Matrix<rdf::bpc::Cell> getMatrixResults() const {
                return _matrixResults;
            }

            void setMatrixResults(rdf::bpc::Matrix<rdf::bpc::Cell> _matrixResults) {
                this->_matrixResults = _matrixResults;
            }

            Task getTask() const {
                return _task;
            }

            void setTask(Task _task) {
                this->_task = _task;
            }
            int getResultSize() const {
                return _resultSize;
            }

            void setResultSize(int _resultSize) {
                this->_resultSize = _resultSize;
            }

            bool isStatus() const {
                return _status;
            }

            void setStatus(bool _status) {
                this->_status = _status;
            }
    };  
    
}

#endif /* NODERESULT_H */

