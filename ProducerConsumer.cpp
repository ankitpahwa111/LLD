// 1. Models - Topic , Consumer , Message (not required)
std::condition_variable cv;
std::mutex m;

class Consumer{
    public:
    string consumerID;
    void consumeMessage(string message) {
        cout<<this->consumerID<<" consumed message "<<message<<endl;
    }
};

class Topic {
    public:
    string topicName;
    vector<Consumer>consumerList;
    void addConsumer(Consumer c){
        this->consumerList.push_back(c);
    }
};

unordered_map<string, vector<string>> kafka;
unordered_map<string, Topic> topicId_to_Topic;

void topicConsumer(string topicId){
    int val = 100;
    while(val) {
        // we should use condition variable
        unique_lock<mutex> lock(m);
        cv.wait(lock, [topicId]{return kafka[topicId].size()>0 ? true : false;});
        cout<<topicId<<" "<<val<<endl;
        vector<std::thread>threads;
        for(auto& message: kafka[topicId]) {
            for(auto & consumer: topicId_to_Topic[topicId].consumerList) {
                thread t(&Consumer::consumeMessage, consumer, message);
                threads.push_back(move(t));
            }
        }
        for(auto &thread: threads) thread.join();
        kafka[topicId].clear();
        lock.unlock();
        cv.notify_all();
        val--;
    }
}

void publishMessage(string topicId, string message){
    m.lock();
    kafka[topicId].push_back(message);
    m.unlock();
    cv.notify_all();
}

int main() {
    // drive code
    Topic c1;
    c1.topicName = "Ankit";
    c1.consumerList = {};
    Topic c2;
    c2.topicName = "Pahwa";
    c2.consumerList = {};
    Topic c3;
    c3.topicName = "Topic3";
    c3.consumerList = {};
    Consumer t1;
    t1.consumerID = "Cons1";
    Consumer t2;
    t2.consumerID = "Cons2";
    Consumer t3;
    t3.consumerID = "Cons3";
    Consumer t4;
    t4.consumerID = "Cons4";
    Consumer t5;
    t5.consumerID = "Cons5";
    Consumer t6;
    t6.consumerID = "Cons6";
    c1.addConsumer(t1);
    c1.addConsumer(t2);
    c2.addConsumer(t3);
    c2.addConsumer(t4);
    c3.addConsumer(t5);
    c3.addConsumer(t6);
    topicId_to_Topic["Ankit"] = c1;
    topicId_to_Topic["Pahwa"] = c2;
    topicId_to_Topic["Topic3"] = c3;
    kafka["Ankit"] = {};
    kafka["Pahwa"] = {};
    kafka["Topic3"] = {};
    thread th1(topicConsumer, "Ankit");
    thread th2(topicConsumer, "Pahwa");
    thread th3(topicConsumer, "Topic3");
    publishMessage("Ankit", "Message1");
    publishMessage("Pahwa", "Message2");
    publishMessage("Topic3", "Message3");
    publishMessage("Topic3", "Message4");
    th1.join();
    th2.join();
    th3.join();
}







