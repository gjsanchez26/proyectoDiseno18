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
#include <queue>

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


    void run();
    
    void connect(std::vector<Estructura::Node> structure,  rdf::Task task, std::priority_queue<rdf::Task> tasks);
    
    

    /*struct ThreadStruct {
        std::thread th;
        struct ThreadStruct *next;
    } taskStruct;

    struct QueueThreads {
        ThreadStruct *first;
        ThreadStruct *last;
    } queueThreads;

    void add(struct QueueThreads& threads, std::thread th);

    void runThread(std::thread th); //, std::vector<Estructura::Node> structure, QueueTask::Queue tasks, std::vector<std::thread> &threads ,int numberThreads*/

private:
    //struct ThreadStruct *createThread(std::thread th);

    //void addQueue(struct QueueThreads &threads, std::thread th);
    
    void sync();

};

#endif /* QUEUETHREAD_H */

