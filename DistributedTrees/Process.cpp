#include "Process.h"

void Process::command_line(int argcin, char* argvin[]) {
    cout << "I will look for mi ip \n";
    _range= setImageRange("localhost");
 
}

inline void Process::initialize(void) {
     

    _scheduler = new treeScheduler();
     configData *data = new configData( VECTOR_AMOUNT,
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
    num_jobs = 32; // convert argument to integer "a - to - i"
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
    
    pair<int,int> step;
    //pair<int,int> range(0,100);
    pair<int,int> fail(-1,-1);
    
    step = _scheduler->getNextNode();
    cout << "Get Node: ("<< step.first << "," << step.second << ")\n";
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

    
}

void Process::work(Message & result_message, const Message & job_message) const {
    // Extract job information from "job" message
    pair<int,int> step;
    pair<int,int> range;
    
    job_message >> step;
    job_message >> range;
            
    pair<int,int> test(-1,-1);
    if(step != test) {
        pair<int,int> result;
        result.first = step.first * step.first;
        result.second = step.second * step.second;
        string name = "localhost";
        string IP = getNodeIP(name);
        
        cout << IP << " is working with Tree: "<< step.first << " Node"<< step.second <<" Range [" << range.first << "," << range.second << "] \n" ;
        int time = rand() % 10000000 + 100000;
        usleep(time);
        result_message << step;
        result_message << range;
        result_message << result;
    }
    else if (step == range) {
        cout << "Don't need to be calculated: \n";
        pair<int,int> result;
        result.first = -1;
        result.second = -1;
        result_message << step;
        result_message << range;
        result_message << result;
    }
    
}

inline void Process::accept(const Message & result_message) {
    pair<int,int>  step; 
    pair<int,int>  range;
    pair<int,int>  result; 
    result_message >> step;
    result_message >> range;
    result_message >> result;
    pair<int,int> test(-1,-1);

    if(test != result){
        std::cout << "Process::read from working --> Job (" << step.first << "," << step.second<< ")\n";
        _scheduler-> addResult(step,result);
    }
    else {
        std::cout << "Process::read from no working --> Job (" << step.first << "," << step.second<< ")\n";
        //accept(result_message);
    }
           
}

inline void Process::finalize(void) {
    std::cout << "  -------- Process::finalize ---------- \n";
    std::cout << "  finished!\n";
    _scheduler-> showResults();  
}

inline string Process::getNodeIP(string _pName) const{
    
    hostent * record = gethostbyname(_pName.c_str());
    if(record == NULL)
    {
		printf("%s is unavailable\n", "Node_1");
                string _null= "null";
                return _null;
		
    }
    else {
        in_addr * address = (in_addr * )record->h_addr;
        string ip_address = inet_ntoa(* address);
        if (ip_address.compare("127.0.0.1") == 0){
            cout << "Node_1";
        }   
        else if (ip_address.compare("172.21.6.81")== 0)
            cout << "Node_5";
        else if (ip_address.compare("172.21.6.82")== 0)
            cout << "Node_3";
        else if (ip_address.compare("172.21.6.83")== 0)
            cout << "Node_4";
        else cout << "No Found";
        return ip_address;
        
        }

}

inline pair<int,int> Process::setImageRange(string _pName) const {
    //ANALYZE MEMORY DATA BY NODE
    pair<int,int> range(10,10);
    return range;
}

    
    
    





