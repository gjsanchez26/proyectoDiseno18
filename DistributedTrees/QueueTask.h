/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueTask.h
 * Author: will
 *
 * Created on 22 de mayo de 2018, 09:03 AM
 */

#ifndef QUEUETASK_H
#define QUEUETASK_H
#include <vector>
#include <iostream>

class QueueTask {
public:
    QueueTask();
    QueueTask(const QueueTask& orig);
    virtual ~QueueTask();
    //void addTaskQueue(std::vector<std::vector<int>>& tasks, std::vector<int> task);
    //void getNumberTasks(std::vector<std::vector<int>> tasks, int& NumberTasks);

    struct TaskStruct {
        int rank;
        int tree;
        int node;
        struct TaskStruct *next;
    } taskStruct;

    struct Queue {
        TaskStruct *first;
        TaskStruct *last;
    } queue;



    void displayQueueTasks(struct Queue tasks);

    void add(struct Queue &tasks, int rank, int tree, int node);

    void isEmpty(struct Queue tasks, bool &empty);

    void pop(struct Queue &tasks, struct TaskStruct &task);

    void getNumberElements(struct Queue &tasks, int &numberElements);

private:
    struct TaskStruct *createTask(int rank, int tree, int node);

    void sortPriority(struct Queue &tasks);

    void addQueue(struct Queue &tasks, int rank, int tree, int node);

};

#endif /* QUEUETASK_H */
