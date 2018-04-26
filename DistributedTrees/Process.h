/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Process.h
 * Author: gabo
 *
 * Created on April 19, 2018, 2:35 PM
 */
#include "cluster-delegator.hpp"
#include "Config.h"
#include <iostream>
#include <tuple>

#ifndef PROCESS_H
#define PROCESS_H

using namespace std;

class Process : public Coordinator_Worker_Process {
public:
    //void command_line(int argcin, char * argvin []);
    int  prepare ( Message & job_message );
    void initialize ( void );
    void work ( Message & result_message, const Message & job_message ) const;
    void accept(Message const& result_message);
    void finalize ( void );
private:
  int num_jobs_sent;
  int num_jobs;
};

#endif /* PROCESS_H */

