#include "Process.h"

void Process::command_line(int argcin, char* argvin[]) {
    cout << "I will look for mi ip \n";
    _rank  = getNodeIP("localhost");
    _range = setImageRange("localhost");
}

inline void Process::initialize(void) {
    _scheduler          = new treeScheduler();
     configData *data   = new configData( VECTOR_AMOUNT,
                                        THRESHOLD_AMOUNT,
                                        TREE_AMOUNT, 
                                        PROCESS_AMOUNT, 
                                        TEST_IMAGES_AMOUNT,
                                        TRAIN_IMAGES_AMOUNT,
                                        LOG_VERBOSITY,
                                        NOTICED_TIME,
                                        TRAINNING_METHOD, 
                                        STOP_METHOD, 
                                        SELECTION_METHOD);
     
    _scheduler->intializateMatix(*data);
    
    std::cout << "  -------------- Process::initialize --------------- \n";
    num_jobs_sent = 0;
    num_jobs = 2; // convert argument to integer "a - to - i"
    std::cout << "  initialized with " << num_jobs << " jobs! \n";
    std::cout << "  initialized with jobs! \n";
    printf("Checking available processors...");
    if (system(NULL)) puts("Ok");  
    else exit(EXIT_FAILURE);
    printf("Cluster Description");
    int i = system("lscpu | grep -E \'^Model name|^Thread|^Core|^Socket|^CPU\\('");
}

inline int Process::prepare(Message & job_message) {
    // Check if done
    if (num_jobs_sent == num_jobs)  return 1;
    if (_scheduler->getStatus())    return 1; //Finish
    if (rand() % 2) return 2; // make sure 2 option works
    // If not done, prepare next job
    int job_number = num_jobs_sent;
    
    vector<vector<pair<int,int>>> step;
    //pair<int,int> range(0,100);
    pair<int,int> fail(-1,-1);
    
    step = _scheduler->getMatrixSteps();
    job_message << step;
    job_message << _range;
    
    cout << "Queue lenght: ("<< step.size()<< ")\n";
    ++num_jobs_sent;
    return 0;
    /*
        if(step == fail){
            job_message << step;
            job_message << fail;
            return 0;
        }
        else {
            job_message << step;
            job_message << _range;
            ++num_jobs_sent;
            std::cout << "Process::write --> Prepared job number " << job_number << "\n";
            return 0; // Prepared a job
        }
     * */

    
}

void Process::work(Message & result_message, const Message & job_message) const {
    vector<pair<int,int>> worked;
    vector<pair<int,int>> results;
    if(_rank== 0){
            // Extract job information from "job" message
        vector<vector<pair<int,int>>> step;
        
        pair<int,int> range;
        pair<int,int> result;
        result.first = 0;
        result.second = 0;

        job_message >> step;
        job_message >> range;


        pair<int,int> test(-1,-1);
        cout << "working with queue length: "<< step.size() << "\n";
        for(int i = 0; i<step.size();i++){

            for(int j = 0; j<step.size(); j++){
                cout<< "NODE:"<<_rank<< " WORKING WITH: ";
                cout<< "(" << step.at(i).at(j).first << "," << step.at(i).at(j).second << ") \n";
                int time = rand() % 1000000 + 10000;
                usleep(time);
                pair<int,int> newStep;
                newStep.first = step.at(i).at(j).first ;
                newStep.second = step.at(i).at(j).second;
                
                pair<int,int> result;
                result.first = newStep.first+1;
                result.second = newStep.second+10;
                
                worked.push_back(newStep);
                results.push_back(result);
                

            }
            result_message << worked;
            result_message << results;
            result_message << _rank;
            
            
                       
        }



        
        
    }
    else{
        cout<< "IM THE MASTER \n";
    
    }
}

inline void Process::accept(const Message & result_message) {
    vector<pair<int,int>>  step; 
    pair<int,int>  range;
    vector<pair<int,int>>  result; 
    int rank;
    result_message >> step;
    result_message >> result;
    result_message >> rank;
    
    for(int i = 0; i< step.size();i++){
        std::cout << "Process::read from NODE:"<< rank<<" working --> Job (" << step.at(i).first << "," << step.at(i).second<< ") ";
      std::cout << "RESULT --> Job (" << result.at(i).first << "," << result.at(i).second<< ")\n";
      _scheduler->addResult(_rank,step.at(i),result.at(i));
    
    
    }
  
    

  
}

inline void Process::finalize(void) {
    std::cout << "  -------- Process::finalize ---------- \n";
    std::cout << "  finished!\n";
    _scheduler-> showResults();  
}

inline int Process::getNodeIP(string _pName) const{
    
    hostent * record = gethostbyname(_pName.c_str());
    if(record == NULL){
        printf("%s is unavailable\n", "Node_1");
        string _null= "null";
        return -1;	
    }
    else {
        
        in_addr * address  =  (in_addr * )record->h_addr;
        string  ip_address =  inet_ntoa(* address);
        
        if (ip_address.compare("127.0.0.1") == 0){
            cout   << "Node_1" ;
            return 0;
        }   
        else if (ip_address.compare("172.21.6.81")== 0){
            cout << "Node_2";
            return 1;
        }
            
        else if (ip_address.compare("172.21.6.82")== 0){
            cout << "Node_3";
            return 2;
        
        }   
        else if (ip_address.compare("172.21.6.83")== 0){
            cout << "Node_4";
            return 3;
        }
        else {
            cout << "No Found";
            return -1;
        }
    }

}

inline pair<int,int> Process::setImageRange(string _pName) const {
    //ANALYZE MEMORY DATA BY NODE
    pair<int,int> range(10,10);
    return range;
}

    
    
    





