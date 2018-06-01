/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueThread.cpp
 * Author: will
 * 
 * Created on 22 de mayo de 2018, 09:03 AM
 */

#include <exception>

#include "QueueThread.h"
#include "Scheduler.h"

QueueThread::QueueThread() {
}

QueueThread::QueueThread(const QueueThread& orig) {
}

QueueThread::~QueueThread() {
}

/*struct QueueThread::ThreadStruct *QueueThread::createThread(std::thread th) {
    struct QueueThread::ThreadStruct *newThread = new (struct QueueThread::ThreadStruct);
    newThread->th = move(th);
    return newThread;
}


void QueueThread::addQueue(QueueThreads& threads, std::thread th) {
    struct QueueThread::ThreadStruct *aux = createThread(move(th));
    aux->next = 0;

    if (threads.first == NULL) {
        threads.first = aux;
    } else {
        threads.last->next = aux;
    }

    threads.last = aux;
}



void QueueThread::add(QueueThreads& threads, std::thread th) {
    addQueue(threads, move(th));
}


void QueueThread::runThread(std::thread th){
    th.join();
}*/


void init(std::vector<Estructura::Node> structure, rdf::Task task) {
    std::cout << "From Thread ID : " << std::this_thread::get_id() << "\n";


    Estructura estructura; //para visualizar la imagen
    cv::Mat img; //para sacar la imagen de la estrctura
    //img = structure[0].imageLabel;
    //estructura.seeImageLabel(img);

    /*std::vector<Estructura::Pixel> pixel = structure[0].points;
    for (int j = 0; j < pixel.size(); j++) {
        std::cout << pixel[j].point << "\n";

    }*/

    std::cout << "el rank es: " << task.getRank() << "\n";
    std::cout << "de la tarea es: " << task.getTree() << "\n";

    //std::cout << "nodo es: " << structure[0].node << "\n";
    std::cout << "Si esta trabajando" << "\n";
    std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
    int v2 = rand() % 2 + 1;
    sleep(v2);
}

void QueueThread::run() {
    std::unique_lock<std::mutex> lck(mtx);
    while (1) {


        while (!ready) {
            if(!tasks.empty()){
                sync();
            }
            cv.wait(lck);
            
            //lck.lock();
        }

        thread = std::thread(init, structure, task);


        QueueThread::thread.detach();

        Scheduler scheduler;
        scheduler.addThreadQueue(*this, structure, tasks);
        ready = false;
    }
}

void QueueThread::connect(std::vector<Estructura::Node> structure, rdf::Task task, std::priority_queue<rdf::Task> tasks) {
    QueueThread::structure = structure;
    QueueThread::task = task;
    QueueThread::tasks = tasks;
    sync();
    //run();
}

void QueueThread::sync() {
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    lck.unlock();
    cv.notify_one();
}