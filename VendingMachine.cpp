#include <bits/stdc++.h>
using namespace std;

class Inventory
{
public:
    unordered_map<string, int> aisleToCount;
    unordered_map<string, int> aisleToPrice;
};

class MachineBank{
    public:
    int coins;
    int notes;
    MachineBank()
    {
        coins = 0;
        notes = 0;
    }
};

class Currency
{
public:
    
    int coinVal;
    int noteVal;
    Currency(){
        this->coinVal = 1;
        this->noteVal = 2;
    }
};

class VendingMachineService
{
public:
    const int DEFAULT_COUNT_PER_AISLE = 10;
    int DEFAULT_COIN_VALUE = 1;
    int DEFAULT_NOTE_VALUE = 2;
    Inventory inv;
    MachineBank bank;
    Currency currencyVal;
    VendingMachineService(){
        inv.aisleToCount["B6"] = 10;
        inv.aisleToCount["A1"] = 10;
        inv.aisleToCount["A5"] = 10;
        inv.aisleToCount["A10"] = 10;
        inv.aisleToCount["C4"] = 10;
        inv.aisleToCount["E4"] = 10;
        inv.aisleToCount["L9"] = 10;
        inv.aisleToCount["G2"] = 10;
        inv.aisleToCount["D3"] = 10;
        inv.aisleToCount["L7"] = 10;

        inv.aisleToPrice["B6"] = 100;
        inv.aisleToPrice["A1"] = 90;
        inv.aisleToPrice["A5"] = 12;
        inv.aisleToPrice["A10"] = 9;
        inv.aisleToPrice["C4"] = 77;
        inv.aisleToPrice["E4"] = 10;
        inv.aisleToPrice["L9"] = 12;
        inv.aisleToPrice["G2"] = 10;
        inv.aisleToPrice["D3"] = 10;
        inv.aisleToPrice["L7"] = 5;

        bank.coins = 100;
        bank.notes = 100;
    }
    void addProduct(string aisle, int count)
    {
        if (inv.aisleToCount[aisle] + count > DEFAULT_COUNT_PER_AISLE)
        {
            cout << "Sorry Aisle is Full " << endl;
            return;
        }
        inv.aisleToCount[aisle] += count;
        cout << "Products added " << endl;
        return;
    }
    void showPrice(string aisle){
        if(inv.aisleToPrice.count(aisle)==0){
            cout<<"Sorry Wrong Aisle   "<<endl;
        }
        cout<<inv.aisleToPrice[aisle]<<endl;
    }

    bool canChange(int money){
        if(bank.coins*currencyVal.coinVal >= money) return true;
        int reqdNotes = money/currencyVal.noteVal;
        int remains = money%currencyVal.noteVal;
        if(reqdNotes <= bank.notes and remains<=bank.coins) return true;
        return false;
    }

    pair<int,int>createChange(int money){
        if(bank.coins*currencyVal.coinVal >= money) return {0,money};
        int reqdNotes = money/currencyVal.noteVal;
        int remains = money%currencyVal.noteVal;
        if(reqdNotes <= bank.notes and remains<=bank.coins) return {reqdNotes, remains};
        return {};
    }

    void buyProduct(string aisle, int notes, int coins){
        if(inv.aisleToPrice.count(aisle)==0){
            cout<<"Sorry Wrong Aisle   "<<endl;
        }
        int totalMoney = coins*currencyVal.coinVal + notes*currencyVal.noteVal;
        if(totalMoney<inv.aisleToPrice[aisle]){
            cout<<"Sorry , the entered money is less  "<<endl;
            return;
        }
        int moneyToChange = totalMoney - inv.aisleToPrice[aisle];
        if(!canChange(moneyToChange)){
            cout<<"Sorry , We dont have the change  "<<endl;
            return;
        }
        inv.aisleToCount[aisle]--;
        bank.coins+=coins;
        bank.notes+=notes;
        pair<int,int> change = createChange(moneyToChange);
        bank.notes-=change.first;
        bank.coins-=change.second;
        cout<<"Thank you for Purchasing , your change is "<<change.first<<" Notes and "<<change.second<<" coins, Come again  "<<endl;
        return;
    }
};

int main()
{
    VendingMachineService machine;
    machine.addProduct("B6", 3);
    machine.addProduct("B6", 4);
    machine.addProduct("B6", 4);
    machine.showPrice("A1");
    machine.showPrice("A5");
    machine.showPrice("J0");
    machine.buyProduct("B6", 50, 4);
}
