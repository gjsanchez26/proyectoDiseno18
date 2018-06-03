
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "TrainManager.h"
#include "Resources.h"



int main()
{

    //rdf::TrainManager _trainer;
    //_trainer.validateConfiguration();
    //_trainer.initPlatform();
    //_trainer.sendingNodes();
   // _trainer.sendingResults();    
    
    rdf::DistributionManager _manager;
    _manager.transferResources();

    _manager.transferRanges();
    rdf::Task _task;
    _task.setRank(420);
    _task.setTree(1);
    _task.setNode(2);
    _task.setStatus(3);
    
    rdf::Task _task2;
    _task2.setRank(430);
    _task2.setTree(1);
    _task2.setNode(2);
    _task2.setStatus(3);
    
    rdf::Task _task3;
    _task3.setRank(400);
    _task3.setTree(1);
    _task3.setNode(2);
    _task3.setStatus(3);
    
    rdf::Task _task4;
    _task4.setRank(40);
    _task4.setTree(1);
    _task4.setNode(2);
    _task4.setStatus(3);
    
    rdf::Task _task5;
    _task5.setRank(4000);
    _task5.setTree(1);
    _task5.setNode(2);
    _task5.setStatus(3);
    
    rdf::Task _task6;
    _task6.setRank(10);
    _task6.setTree(1);
    _task6.setNode(2);
    _task6.setStatus(3);
    
    
    
    _manager.transferNodes(_task);
    _manager.transferNodes(_task2);
    _manager.transferNodes(_task3);
    _manager.transferNodes(_task4);
    _manager.transferNodes(_task5);
    _manager.transferNodes(_task6);
    
    
      // _manager.transferResults();
    

    
    

       


  return 0;
}
