#include <bits/stdc++.h>
using namespace std;

// Process is fairly simple
// Define Store - repository for mappings of user vs non-delivered orders, repository of lockers,repository of users, mapping of occupiedLocker vs order vs code
// Define Models - User , Order, Locker, Code
// Define Services - LockerService, CodeService, DeliveryService

class UserModel
{
private:
    string name;
    string email;

public:
    UserModel(string name, string email)
    {
        this->name = name;
        this->email = email;
    }
    string getName()
    {
        return this->name;
    }
    string getEmail()
    {
        return this->email;
    }
};

enum LockerSize
{
    S,
    M,
    L
};

class LockerModel
{
private:
    LockerSize size;
    int latitude;
    int longitude;
    bool isOccupied;
    string id;

public:
    LockerModel(LockerSize size, int lat, int lon)
    {
        this->size = size;
        this->latitude = lat;
        this->longitude = lon;
        this->isOccupied = false;
    }
    void setOccupancy(bool isOccupied)
    {
        this->isOccupied = isOccupied;
    }
    bool getOccupancy()
    {
        return this->isOccupied;
    }
    LockerSize getSize()
    {
        return this->size;
    }
    pair<int, int> getCoordinates()
    {
        return {this->latitude, this->longitude};
    }
    string getId()
    {
        return this->id;
    }
};

// util idgen

class OrderModel
{
private:
    bool isDelivered;
    bool isLockerFriendly;
    LockerSize size;
    UserModel user;
    string id;

public:
    OrderModel(bool isLockerFriendly, LockerSize size, UserModel user)
    {
        this->isDelivered = false;
        this->isLockerFriendly = isLockerFriendly;
        this->user = user;
        this->size = size;
        this->id = generateID();
    }
    UserModel getUserWhoPlacedOrder()
    {
        return this->user;
    }
    void setDeliverStatus(bool st){
        this->isDelivered = st;
    }
    bool getDeliveryStatus()
    {
        return isDelivered;
    }
    bool isLockerFriendly()
    {
        return this->isLockerFriendly;
    }
    LockerSize getSize()
    {
        return this->size;
    }
    string getId(){
        return this->id;
    }
};

string generateID()
{
    // return order.getUserWhoPlacedOrder().getEmail() + "#";
    return "123";
}

class CodeModel
{
    int code;
    int creationDate;

public:
    CodeModel(int code, int creation)
    {
        this->code = code;
        this->creationDate = creation;
    }
    int getCode() { return this->code; }
    int getDate() { return this->creationDate; }
};

// Repositories

class Repositories{
    public:
        vector<UserModel> users;
        vector<OrderModel>orders;
        unordered_map<string, list<OrderModel>> undelivered_packages;
        vector<LockerModel> lockers;
        unordered_map<string, pair<OrderModel,CodeModel>> occupiedLockerMappings;
};

Repositories repo;

// Services

class LockerService{
    public:
        string findClosestUnoccupiedLocker(int x, int y, list<LockerModel>shortListedLockers){
            string bestLockerId = "";
            int min = INT_MAX;
            for(auto locker: shortListedLockers){
                // calc Hamiltonian Dist and check
                int dist = abs(locker.getCoordinates().first - x) + abs(locker.getCoordinates().second - y);
                if(dist < min){
                    min = dist;
                    bestLockerId = locker.getId();
                }
            }
            return bestLockerId;
        }
        string AssignLocker(int x, int y, OrderModel order){
            list<LockerModel>shortListedLockers;
            for(auto locker : repo.lockers){
                if(locker.getSize() == order.getSize()) shortListedLockers.push_back(locker);
            }
            string bestLockerId = this->findClosestUnoccupiedLocker(x,y,shortListedLockers);
            // if(bestLockerId == "") return "NO Locker is Available";
            return bestLockerId;
        }
};

class CodeService{
    const int DEFAULT_CODE_EXPIRY_DURATION = 3;
    public:
        CodeModel getCode(){
            return CodeModel(123456, 1212);
        }
        bool isCodeValid(CodeModel codeModel, int date){
            if(date - codeModel.getDate() > 3) return false;
            return true;
        }
};


class PickupService{
    public:
        bool pickup(string userEmail, string lockerID, int code){
            if(repo.occupiedLockerMappings.count(lockerID)==0){
                cout<<"Locker ID is wrong does not exist :( "<<endl;
                return 0;
            }
            CodeModel codeModel = repo.occupiedLockerMappings[lockerID].second;
            CodeService codeService;
            if(!codeService.isCodeValid(codeModel, 1214)){
                cout<<"Code is expired , Sorry :( "<<endl;
                return 0;
            }
            for(auto locker: repo.lockers){
                if(locker.getId() == lockerID){
                    locker.setOccupancy(0);
                    break;
                }
            }
            for(auto order : repo.orders){
                if(order.getId() == repo.occupiedLockerMappings[lockerID].first.getId()){
                    order.setDeliverStatus(1);
                    break;
                }
            }
            for(auto order : repo.undelivered_packages[userEmail]) {
                if(order.getId() == repo.occupiedLockerMappings[lockerID].first.getId()){
                    repo.undelivered_packages[userEmail].remove(order);
                    break;
                }
            }
            repo.occupiedLockerMappings.erase(lockerID);
        }
};

class DeliveryService{
    LockerService lockerService;
    public:
        pair<string, int> deliverOrderToLocker(string userEmail, OrderModel order, int lat, int lon){
            string lockerId = lockerService.AssignLocker(lat, lon, order);
            if(lockerId == ""){
                cout<<"No locker found "<<endl;
                return {};
            }
            CodeModel codeModel(123456, 1212);

            if(repo.occupiedLockerMappings.count(lockerId)==0){
                repo.occupiedLockerMappings[lockerId] = {order, codeModel};
            }
            for(auto locker: repo.lockers){
                if(locker.getId() == lockerId){
                    locker.setOccupancy(1);
                    break;
                }
            }
            return {lockerId, codeModel.getCode()};
        }
};


int main(){
    // create lockers, orders , users, and mappings of user to pending orders in repo
    // give option to choose from 1. Deliver Package to locker 2. Pickup package from locker
    // call deliver() for 1. and pickup() for 2.
}















