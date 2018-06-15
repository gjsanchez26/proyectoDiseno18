
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
    _task.setRank(1);
    _task.setTree(1);
    _task.setNode(2);
    _task.setStatus(0);
         
    _manager.transferNodes(_task);

   // _manager.transferNodes(_task2);
   // _manager.transferNodes(_task3);
   // _manager.transferNodes(_task4);
   // _manager.transferNodes(_task5);
   // _manager.transferNodes(_task6);
    
    
      // _manager.transferResults();
    

    
    

       


  return 0;
}
