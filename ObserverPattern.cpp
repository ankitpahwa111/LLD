//Observer Design Pattern , where one publisher publishes message and many subscribers listen to that msg and process it in different manner .

// Abstract class -- made just for inheritance ( just like interface ) , it has at least one pure virtual function
class ISubscriber{
    virtual void notify(string msg) = 0; // pure virtual function -- just for overriding
};
// Subsciber implementation
class User : public ISubscriber{
    int userId;
    public:
        User(int userId){
            this->userId = userId;
        }
        void notify(string msg){
            cout<<"User "<<userId<<" got the msg "<< msg << endl;
        }
};  
// Publisher Implementation
class Group{
    list<User*> users;
    public:
        Group(){
            list<User*> l;
            users = l;
        }
        void AddSubscriber(User * u){
            users.push_back(u);
        }
        void removeSubscriber(User *u){
            users.remove(u);
        }
        void NotifySubs(string msg){
            for(auto user : this->users){
                user->notify(msg);
            }
        }
};
int main() {
    Group *g = new Group;
    User * u1 = new User(1);
    User * u2 = new User(2);
    User * u3 = new User(3);
    g -> AddSubscriber(u1);
    g -> AddSubscriber(u2);
    g -> AddSubscriber(u3);
    g->NotifySubs("Hello 👋 ");
    g->removeSubscriber(u1);
    g->NotifySubs("Hello again 👋 ");
}








