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

/*void init(std::vector<Estructura::Node> structure, QueueTask::TaskStruct task) {
    std::cout << "From Thread ID : " << std::this_thread::get_id() << "\n";


    Estructura estructura; //para visualizar la imagen
    cv::Mat img; //para sacar la imagen de la estrctura
    //img = structure[0].imageLabel;
    //estructura.seeImageLabel(img);

    //std::vector<Estructura::Pixel> pixel = structure[0].points;
    //for (int j = 0; j < pixel.size(); j++) {
    //    std::cout << pixel[j].point << "\n";

    //}

    std::cout << "el rank es: " << task.rank << "\n";
    std::cout << "de la tarea es: " << task.tree << "\n";

    std::cout << "nodo es: " << structure[0].node << "\n";
    std::cout << "Si esta trabajando" << "\n";
    std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
    int v2 = rand() % 10 + 1;
    sleep(v2);
}*/

Scheduler::Scheduler() {
    //Scheduler::threads.push_back(std::thread thread1);

    for (int i = 0; i < 8; i++) {
        //Scheduler::threads.push_back(std::thread(imprimir));
        QueueThread thread;




        //queueThread.thread;
        //std::thread th = move(queueThread.thread);
        Scheduler::threads.push(thread);
    }
    //QueueThread queueThread;
    //queueThread.thread;


}

Scheduler::Scheduler(const Scheduler& orig) {
}

Scheduler::~Scheduler() {
}

void Scheduler::assingTask(std::vector<Estructura::Node> structure, rdf::Task &task) {


    tasks.push(task);
 

    int numThreads = threads.size();
    checkQueues(structure, tasks,0);
    

}

void Scheduler::checkQueues(std::vector<Estructura::Node> structure,std::priority_queue<rdf::Task> tasks, int numberThreads) {

    bool empty = false;
    int numberElements;

    if (!tasks.empty()) {

            rdf::Task task = tasks.top();
            tasks.pop();
            sync();

            if (ready && threads.size()>0) {
                //std::thread th = move(Scheduler::threads.pop());

                QueueThread thread = Scheduler::threads.front();
                Scheduler::threads.pop();
                thread.connect(structure, task, tasks);
                //execute.push(thread);
                thread.run();
                ready = false;
                std::cout << threads.size()<<"\n"; 

            } else {
                lock();
            }

            //queueTask.displayQueueTasks(tasks);
            //checkQueues(structure, tasks, numberThreads);
            //queueTask.getNumberElements(tasks, numberElements);
        //}

    } else {

        if (threads.size() != 0) {
            //assingThreadTask(structure, tasks, numberThreads);
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

void Scheduler::addThreadQueue(QueueThread thread,std::vector<Estructura::Node> structure, std::priority_queue<rdf::Task> tasks) {
    QueueThread threadTem;
    Scheduler::threads.push(thread);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    checkQueues(structure,tasks, 0);
}

/*void Scheduler::checkQueues(std::vector<Estructura::Node> structure, QueueTask::Queue tasks, int numberThreads) {
    
    QueueTask queueTask;
    bool empty = false;
    int numberElements;
    
    queueTask.isEmpty(tasks, empty);
    queueTask.getNumberElements(tasks, numberElements);

    if (!empty) {
        QueueTask::TaskStruct task;
        for (int i = 0; i < numberElements; i++) {
            queueTask.pop(tasks, task);
            if (numberThreads < 8) {
                //agrego a la cosa de threads
                threads.push_back(std::thread(init, structure, task));
                numberThreads += 1;
            } else {
                break;
            }
        }
        //llamo a la otrA funcion
        queueTask.displayQueueTasks(tasks);
        assingThreadTask(structure, tasks, numberThreads);
        
    } else {

        if (threads.size() != 0) {
            assingThreadTask(structure, tasks, numberThreads);
        }
    }
}


bool bandera = false;

void Scheduler::assingThreadTask(std::vector<Estructura::Node> structure, QueueTask::Queue tasks, int numberThreads) {
    QueueThread queueThread;
    //int cont = 0;
    sync();
    for (unsigned int i = 0; i < threads.size(); i++) {
        //std::cout << "*******************************************************************" << std::endl;
        std::thread th = move(threads[i]);
        queueThread.runThread(move(th));
        
        //threads.pop_back();
        //numberThreads -= threads.size();
        //checkQueues(structure, tasks, numberThreads);
    }

    //for (auto &t : Scheduler::threads) {
        //t.detach();

        //threads.pop_back();
        //std::cout << "*-----------------------"<< threads.size() << std::endl;
        //numberThreads -= threads.size();
        //checkQueues(structure, tasks, numberThreads);

    //}
    
    //esto sirve
    for (int i = 0; i < numberThreads; i++) {
        threads.pop_back();

    }
    numberThreads = threads.size();

    std::cout << "lo eleemntos en la vcola de threads son "
            << threads.size() << std::endl;
    
    


    if (bandera) {
        QueueTask queueTask;

        queueTask.add(tasks, 0, 1, 2);
        queueTask.add(tasks, 1, 1, 3);
        queueTask.add(tasks, 2, 1, 0);
        queueTask.add(tasks, 3, 1, 1);
        

        bandera = false;

        checkQueues(structure, tasks, numberThreads);
    } else {
        checkQueues(structure, tasks, numberThreads);
    }
}

void Scheduler::sync() {
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_one();
}
 */
