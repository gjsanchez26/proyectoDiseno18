/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scheduler.cpp
 * Author: will
 * 
 * Created on 16 de mayo de 2018, 09:48 AM
 */

#include "Scheduler.h"
#include "QueueTask.h"
#include "NodeResource.h"

Scheduler::Scheduler() {

    for (int i = 0; i < 8; i++) {
        QueueThread thread;
        Scheduler::threads.push(thread);
    }
}

Scheduler::Scheduler(const Scheduler& orig) {
}

Scheduler::~Scheduler() {
}

void Scheduler::start() {
    //threadManager = std::thread(&Scheduler::checkQueues, this, structureTemp, tasks);
    //rdf::Task task;
    //threadManager = std::thread(&QueueThread::connect,QueueThread(), structureTemp, task, tasks);
}

void Scheduler::assingTask(std::vector<Estructura::Node> structure, rdf::Task &task) {

    structureTemp = structure;
    tasks.push(task);
    checkQueues(structure, tasks);

}

void Scheduler::checkQueues(std::vector<Estructura::Node> structure, std::priority_queue<rdf::Task> tasks) {

    if (!tasks.empty()) {

        rdf::Task task = Scheduler::tasks.top();
        Scheduler::tasks.pop();
        sync();



        if (ready && threads.size() > 0) {

            //objeto node result
            rdf::NodeResult nodeResult;
            rdf::NodeResult nodeResultTemp;
            nodeResult.setTask(task);
            QueueThread thread = Scheduler::threads.front();
            Scheduler::threads.pop();
            threadManager = std::thread(&QueueThread::connect, QueueThread(), structure, task, tasks, std::ref(nodeResult));
            if (threadManager.joinable())
                threadManager.join();
            ready = false;
            addThreadQueue(thread);
            //nodeResult.setMatrixResults(nodeResultTemp.getMatrixResults());
            results.push(nodeResult);
            std::cout << "hsakdlmkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk: ";
            std::cout << results.size() << " \n";
            for (int i = 0; i < results.size(); i++) {
                 rdf::NodeResult nodetemp = results.front();
                 results.pop();
                 nodetemp.getTask().showTask();
                 std::cout << "________________________________________________________________ \n ";
                 nodetemp.getMatrixResults().Print();
                 std::cout << "______________________________****************__________________________________\n ";

            }

            //nodeResult.getMatrixResults().Print();
            //results.push(nodeResult);

        } else {
            lock();
        }

    } else {

        if (threads.size() != 0) {
        }
    }
}

void Scheduler::sync() {
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_one();
}

void Scheduler::lock() {
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready) {
        cv.wait(lck);
    }
}

void Scheduler::addThreadQueue(QueueThread thread) {
    QueueThread threadTem;
    Scheduler::threads.push(thread);
}

void Scheduler::getResult(std::queue<rdf::NodeResult> &results){
    results = Scheduler::results;
}

void Scheduler::cleanQueueResult(){
    for (int i = 0; i < results.size(); i++) {
        results.pop();
    }
}
