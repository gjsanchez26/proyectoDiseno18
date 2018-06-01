/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueTask.cpp
 * Author: will
 * 
 * Created on 22 de mayo de 2018, 09:03 AM
 */

#include "QueueTask.h"
#include "Scheduler.h"

QueueTask::QueueTask() {

}

QueueTask::QueueTask(const QueueTask& orig) {
}

QueueTask::~QueueTask() {
}

/*void QueueTask::addTaskQueue(std::vector<std::vector<int> >& tasks, std::vector<int> task){
    tasks.push_back(task);
}

void QueueTask::getNumberTasks(std::vector<std::vector<int>> tasks, int& NumberTasks){
    NumberTasks = tasks.size();
}*/

struct QueueTask::TaskStruct *QueueTask::createTask(int rank, int tree, int node) {
    struct QueueTask::TaskStruct *newTask = new (struct QueueTask::TaskStruct);
    newTask->rank = rank;
    newTask->node = node;
    newTask->tree = tree;
    return newTask;
}

void QueueTask::addQueue(Queue& tasks, int rank, int tree, int node) {
    struct QueueTask::TaskStruct *aux = createTask(rank, tree, node);
    aux->next = 0;

    if (tasks.first == NULL) {
        tasks.first = aux;
    } else {
        tasks.last->next = aux;
    }

    tasks.last = aux;
}

void QueueTask::displayQueueTasks(Queue tasks) {
    struct QueueTask::TaskStruct *aux;

    aux = tasks.first;
    std::cout << "Las tareas son: " << "\n";
    std::cout << "****************" << "\n";

    while (aux != NULL) {
        std::cout << "Tree:  " << aux->tree << " Node:   " << aux->node << " Rank:   " << aux->rank << std::endl;
        aux = aux->next;
    }
}

void QueueTask::sortPriority(Queue& tasks) {
    struct QueueTask::TaskStruct *aux1, *aux2;
    int treeAux;
    int nodeAux;
    int rankAux;

    aux1 = tasks.first;

    while (aux1->next != NULL) {
        aux2 = aux1->next;

        while (aux2 != NULL) {
            if (aux1->tree >= aux2->tree) {

                if (aux1->node > aux2->node) {
                    treeAux = aux1->tree;
                    nodeAux = aux1->node;
                    rankAux = aux1->rank;

                    aux1->tree = aux2->tree;
                    aux1->node = aux2->node;
                    aux1->rank = aux2->rank;

                    aux2->tree = treeAux;
                    aux2->node = nodeAux;
                    aux2->rank = rankAux;
                }
            }

            aux2 = aux2->next;
        }
        aux1 = aux1->next;
    }
}

void QueueTask::add(Queue& tasks, int rank, int tree, int node) {
    addQueue(tasks, rank, tree, node);
    sortPriority(tasks);
}

void QueueTask::isEmpty(Queue tasks, bool& empty) {

    if (tasks.first == NULL) {
        empty = true;
    } else {
        empty = false;
    }
}

void QueueTask::pop(struct Queue &tasks, struct TaskStruct &task) {
    struct QueueTask::TaskStruct *aux;
    aux = tasks.first;

    if (tasks.first != NULL) {
        tasks.first = aux->next;
        aux->next = NULL;

    } else {
        std::cout << "La lista esta vacia" << "\n";
    }
    task = *aux;
    delete aux;
}

void QueueTask::getNumberElements(Queue& tasks, int& numberElements){
    struct QueueTask::TaskStruct *aux;

    aux = tasks.first;
    numberElements = 0;
    while (aux != NULL) {
        aux = aux->next;
        numberElements +=1;
    }
}