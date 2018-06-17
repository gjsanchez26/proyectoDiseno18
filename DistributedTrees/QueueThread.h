/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueThread.h
 * Author: will
 *
 * Created on 22 de mayo de 2018, 09:03 AM
 */

#ifndef QUEUETHREAD_H
#define QUEUETHREAD_H

#include <thread>
#include <vector>
#include "Estructura.h"
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include "Task.h"
#include "NodeResult.h"
#include <queue>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace rdf {
    
    /*
     * This class control to each thread with its respective task
     */
    class QueueThread {
    public:
        QueueThread();
        QueueThread(const QueueThread& orig);
        virtual ~QueueThread();
        std::thread thread;
        std::mutex mtx;
        std::condition_variable cv;
        bool ready = false;
        std::vector<Estructura::Node> structure;
        rdf::Task task;
        std::priority_queue<rdf::Task> tasks;
        rdf::NodeResult nodeResult;


        void run();

        void connect(std::vector<Estructura::Node> structure,  rdf::Task task, std::priority_queue<rdf::Task> tasks,
                rdf::NodeResult &nodeResult);





    private:

        void sync();

    };
}

#endif /* QUEUETHREAD_H */

