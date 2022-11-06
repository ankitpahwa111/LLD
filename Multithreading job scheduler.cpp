#include<iostream>
#include<thread>
#include<chrono>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Job{
    public:
        string jobId;
        bool recurring;
        int repeat_job_after;
        Job(string jobId, bool recurring, int repeat_job_after){
            this->jobId = jobId;
            this->recurring = recurring;
            this->repeat_job_after = repeat_job_after;
        }
        void runJob() {
            cout<<"Executing job id : "<<jobId<<endl;
        }
};
unordered_map<int, vector<Job>> schedule_map;
void addJob(Job j, int timestamp) {
    schedule_map[timestamp].push_back(j);
}
void scheduler(){
    int curr_time = 0;
    while(true) {
        for(auto& job: schedule_map[curr_time]) {
            // schedule jobs in diff threads 
            // cout<<job.jobId<<endl;
            std::thread t(&Job::runJob, job);
            if(job.recurring) {
                addJob(job, curr_time+job.repeat_job_after);
            }
            t.detach();
        }
        curr_time+=2;
        cout<<curr_time<<" ";
        // std::this_thread::sleep_for(2000ms);
        if(curr_time>10) break;
    }
}
int main() {
    std::thread t(scheduler);
    // t.detach();
    Job j1("job1", true, 2);
    addJob(j1,4);
    // cout<<j1.jobId<<endl;
    Job j2("job2", false, 0);
    addJob(j2,2);
    Job j3("job3", true, 2);
    addJob(j3,4);
    Job j4("job4", false, 0);
    addJob(j4,6);
    Job j5("job5", true, 2);
    addJob(j5,8);
    Job j6("job6", false, 0);
    addJob(j6,8);
    Job j7("job7", true, 2);
    addJob(j7,8);
    Job j8("job8", false, 0);
    addJob(j8,8);
    t.join();
}
