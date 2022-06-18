// Singleton Design pattern -- For cases where we only want one instance of a class , for all the modules in the code that same instance should be used 

// This is a Singleton class
class Logger{
    static Logger * logger;
    // Making the constructor private so that no one can instanciate the class
    Logger(){

    }
    public:
    // Making this method static , so that it belongs to the class and not the object , whenever we call this method ,        it will be called by the name of class and it will return the default instance that is created.
    static Logger* getloggerInstance(){
        if(logger == NULL){
            logger = new Logger();
        }
        return logger;
    }
    void log(string str){
        cout<<str<<endl;
    }
};

int main() {
    // client will implement the class via the class name and will/can not create instance by itself
    Logger * logger = Logger::getloggerInstance();
    logger->log("This is crazy !!");
}
