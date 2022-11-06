// Create Logging System , That uses Chain of Responsibility Design Pattern
// Call logger , with types DEBUG , ERROR , INFO and it should decide on its own 

class Logger{
    public:
    Logger * nextLogger;
    Logger (){
        
    }
    Logger(Logger * l) {
        this->nextLogger = l;
    }
    virtual void log(string type , string message){
        this->nextLogger->log(type, message);
    }
};

class DebugLogger : public Logger{
    public:
    DebugLogger(Logger * l){
        this->nextLogger = l;
    }
    void log(string type , string message) {
        if(type == "DEBUG") {
            cout<<"DEBUG: "<<message;
        }else{
            if(this->nextLogger)
                this->nextLogger->log(type, message);
        }
    }
};

class ErrorLogger : public Logger{
    public:
    ErrorLogger(Logger * l){
        this->nextLogger = l;
    }
    void log(string type , string message) {
        if(type == "ERROR") {
            cout<<"ERROR: "<<message;
        }else{
            if(this->nextLogger)
                this->nextLogger->log(type, message);
        }
    }
};

class InfoLogger : public Logger{
    public:
    InfoLogger(Logger * l){
        this->nextLogger = l;
    }
    void log(string type , string message) {
        if(type == "INFO") {
            cout<<"INFO: "<<message;
        }else{
            if(this->nextLogger)
                this->nextLogger->log(type, message);
        }
    }
};

int main() {
    Logger * logger = new Logger(new DebugLogger(new InfoLogger(new ErrorLogger(NULL))));
    logger->log("ERROR", "Abe jaa naa");
}

