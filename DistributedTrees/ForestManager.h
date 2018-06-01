/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeManager.h
 * Author: gabo
 *
 * Created on May 17, 2018, 4:24 PM
 */
#include "Task.h"
#include <iostream>
#include "Config.h"
#include <vector>
#include <map>
#include <iterator>
#include "Config.h"
#include <stdlib.h>
#include <unistd.h>
#include <tuple>
#include "NodeResult.h"

#ifndef TREEMANAGER_H
#define TREEMANAGER_H

using namespace std;

namespace rdf {
    /** Thisclass allow manage train nodes, trees. 
        */
    class ForestManager {

        private:
            vector<rdf::Task>                    _matrixSteps; 
            vector<vector<rdf::NodeResult>>      _results;
            bool                            _status;
            Task                            _result;
            std::map<Task,rdf::NodeResult>       _resultMap;

        public:
            ForestManager();
            ForestManager(const ForestManager& orig);
            virtual ~ForestManager();

            void initializeForest();
            void showQueue();
            Task &getNextTask();
            bool addResuld(rdf::NodeResult &pResult);

            std::map<Task, rdf::NodeResult> getResultMap() const {
                return _resultMap;
            }

            void setResultMap(std::map<Task, rdf::NodeResult> _resultMap) {
                this->_resultMap = _resultMap;
            }

            vector<Task> getMatrixSteps() const {
                return _matrixSteps;
            }

            void setMatrixSteps(vector<rdf::Task> _matrixSteps) {
                this->_matrixSteps = _matrixSteps;
            }


            rdf::Task getResult() const {
                return _result;
            }
            void setResult(rdf::Task _result) {
                this->_result = _result;
            }
            vector<vector<rdf::NodeResult> > getResults() const {
                return _results;
            }

            void setResults(vector<vector<rdf::NodeResult> > _results) {
                this->_results = _results;
            }

            bool isStatus() const {
                return _status;
            }

            void setStatus(bool _status) {
                this->_status = _status;
            }
    };
}

#endif /* TREEMANAGER_H */

