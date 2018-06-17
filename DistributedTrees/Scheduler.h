/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scheduler.h
 * Author: will
 *
 * Created on 16 de mayo de 2018, 09:48 AM
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <iostream>     // std::cout
#include <stdio.h>
#include <thread>
#include <queue>
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <unistd.h>

#include "Estructura.h"
#include "QueueThread.h"
#include "Task.h"
#include "NodeResult.h"

/*struct comp {

    bool operator()(const Task& a, const Task& b) {
        if (a.tree > b.tree) {
            return a.node > b.node;
        }
    }
};*/

namespace rdf {
    /*
     * This class control the thrads its respective task and assing the new task a thread  
     */
    class Scheduler {
    public:
        Scheduler();
        Scheduler(const Scheduler& orig);
        virtual ~Scheduler();
        void assingTask(std::vector<Estructura::Node> structure, rdf::Task &task);
        void addThreadQueue(QueueThread thread);
        void start();
        void getResult(std::queue<rdf::NodeResult> &results);
        void cleanQueueResult();

        std::queue<rdf::NodeResult> getResults() const {
            return results;
        }

        void setResults(std::queue<rdf::NodeResult> results) {
            this->results = results;
        }



    private:
        //std::vector<std::thread> threads;
        std::queue<rdf::NodeResult> results;
        std::queue<QueueThread> threads;
        std::priority_queue<rdf::Task> tasks;
        std::vector<Estructura::Node> structureTemp;
        std::mutex mtx;
        std::condition_variable cv;
        bool ready = false;
        std::thread threadManager;

        void lock();
        void checkQueues(std::vector<Estructura::Node> structure, std::priority_queue<rdf::Task> tasks);


        //void assingThreadTask(std::vector<Estructura::Node> structure, QueueTask::Queue tasks, int numberThreads);
        void sync();
        //std::priority_queue<Task, std::vector<Task>,comp> tasks;

    };
}


#endif /* SCHEDULER_H */

