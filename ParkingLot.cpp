#include<bits/stdc++.h>
using namespace std;

enum colour{
    RED,
    BLUE,
    GREEN
};

class CarModel{
    private:
        colour carColour;
        string registrationNum;
    public:
        CarModel(colour carColour, string registrationNum){
            this->carColour = carColour;
            this->registrationNum = registrationNum;
        }
        colour getCarColour(){
            return this->carColour;
        }
        string getRegistration(){
            return this->registrationNum;
        }
};

class Slot{
    private:
        bool isOccupied;
        CarModel *parkedCar;
        int slotNum;
    public:
        Slot(){

        }
        Slot(int slotNum){
            this->parkedCar = NULL;
            this->isOccupied = false;
            this->slotNum = slotNum;
        }
        CarModel* getParkedCar(){
            return this->parkedCar;
        }
        int getSlotNum(){
            return this->slotNum;
        }
        bool getOccupancy(){
            return this->isOccupied;
        }
        void setOccupancy(bool occupancy){
            this->isOccupied = occupancy;
        }
        void setCar(CarModel * car){
            this->parkedCar = car;
        }
};

// Parking Service
const int DEFAULT_LOT_SIZE = 100;
class ParkingService{

    private:
        int lotSize;
    public:
        unordered_map<int, Slot> parkingMap;
        unordered_map<string, Slot> registrationNumvsSlot;
        unordered_map<colour, list<Slot>> slotsOfParkedCarColour;
        vector<Slot>slots;
        ParkingService(){
            lotSize = DEFAULT_LOT_SIZE;
            for(int i=1;i<=lotSize;i++){
                Slot s(i);
                slots.push_back(s);
            }
        }
        void parkCar(colour clr , string registration){
            for(int i=1; i<DEFAULT_LOT_SIZE; i++){
                Slot s = slots[i];
                if(s.getOccupancy()==false){
                    // slot is empty
                    CarModel *car = new CarModel(clr, registration);
                    // Slot slot(i);
                    s.setOccupancy(true);
                    s.setCar(car);
                    parkingMap[i] = s;
                    registrationNumvsSlot[registration] = s;
                    if(slotsOfParkedCarColour.count(clr)==0){
                        list<Slot>l;
                        l.push_back(s);
                        slotsOfParkedCarColour[clr] = l;
                    }
                    else{
                        slotsOfParkedCarColour[clr].push_back(s);
                    }
                    cout<<"Receipt: CAR is parked at "<<s.getSlotNum()<<endl;
                    return;
                }
            }
            cout<<"OOPS, no slot empty  !!"<<endl;
            return;
        }
        void unParkCar(string regi){
            if(registrationNumvsSlot.count(regi)){
                cout<<"Sorry , car is not parked in this lot  "<<endl;
                return ;
            }
            slots[registrationNumvsSlot[regi].getSlotNum()].setCar(NULL);
            slots[registrationNumvsSlot[regi].getSlotNum()].setOccupancy(false);
            CarModel *car = registrationNumvsSlot[regi].getParkedCar();
            for(auto slot : slotsOfParkedCarColour[car->getCarColour()]){
                if(slot.getParkedCar()->getRegistration()==regi){
                    slotsOfParkedCarColour[car->getCarColour()].remove(slot);
                    break;
                }
            }
        }
        void printAllCarsofColour(colour clr){
            for(auto slot : slotsOfParkedCarColour[clr]){
                cout<<slot.getParkedCar()->getRegistration()<<endl;
            }
            return;
        }
        void getSlotNumberofCarbyRegNum(string reg){
            cout<<registrationNumvsSlot[reg].getSlotNum()<<endl;
        }
        void printSlotNumbersOfCarsWithColour(colour clr){
            for(auto slot : slotsOfParkedCarColour[clr]){
                cout<<slot.getSlotNum()<<endl;
            }
        }
};

int main(){

    ParkingService parkingService;
    parkingService.parkCar(RED, "ankit");
    parkingService.parkCar(RED, "ankit2");
    parkingService.parkCar(RED, "ankit3");
    parkingService.parkCar(BLUE, "ankit4");
    parkingService.parkCar(BLUE, "ankit5");
    parkingService.parkCar(BLUE, "ankit6");
    parkingService.parkCar(GREEN, "ankit7");

    parkingService.printAllCarsofColour(RED);
    parkingService.printAllCarsofColour(BLUE);
    parkingService.printAllCarsofColour(GREEN);

    parkingService.getSlotNumberofCarbyRegNum("ankit4");
    parkingService.getSlotNumberofCarbyRegNum("ankit7");
    parkingService.getSlotNumberofCarbyRegNum("ankit");

    parkingService.printSlotNumbersOfCarsWithColour(RED);
    parkingService.printSlotNumbersOfCarsWithColour(BLUE);
    parkingService.printSlotNumbersOfCarsWithColour(GREEN);
}





















