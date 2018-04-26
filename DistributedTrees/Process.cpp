#include "Process.h"

inline void Process::initialize(void) {
  
    std::cout << "  -------- Process::initialize ---------- \n";
    num_jobs_sent = 0;
    num_jobs = 20; // convert argument to integer "a - to - i"
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
    if (num_jobs_sent == num_jobs) return 1; //Finish
    if (rand() % 2) return 2; // make sure 2 option works
    // If not done, prepare next job
    int job_number = num_jobs_sent;
    
    pair<int,int> step(1,1);
    pair<int,int> range(0,100);
    
    
    job_message << step;
    job_message << range;
    
    ++num_jobs_sent;
    std::cout << "Process::write --> Prepared job number " << job_number << "\n";
    return 0; // Prepared a job
}

void Process::work(Message & result_message, const Message & job_message) const {
    // Extract job information from "job" message
    pair<int,int> step;
    pair<int,int> range;
    
    job_message >> step;
    job_message >> range;
            
    pair<bool,int> result(true,1);       
    result_message << step;
    result_message << result;
    cout << "Work with Tree: "<< step.first << " Node"<< step.second <<" Range [" << range.first << "," << range.second << "] \n" ;

}

inline void Process::accept(const Message & result_message) {
    pair<int,int>  step; 
    pair<bool,int> result; 
    result_message >> step;
    result_message >> result;
    std::cout << "Process::read --> Job " << result.first << "\n";
            
}

inline void Process::finalize(void) {
    std::cout << "  -------- Process::finalize ---------- \n";
    std::cout << "  finished!\n";
}


