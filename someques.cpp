#include <bits/stdc++.h>
using namespace std;
void showMenu()
{
    cout << "*************** MENU ***********" << endl;
    cout << "1. Show Balance " << endl;
    cout << "2. Deposit " << endl;
    cout << "3. Withdraw " << endl;
    cout << "4. Exit " << endl;
}
int main()
{
    int option = 0;
    double amount = 0;
    do
    {
        showMenu();
        cout << "Option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << amount << endl;
            break;
        case 2:
            double Depositval;
            cout << "Enter amount to be deposited " << endl;
            cin >> Depositval;
            amount += Depositval;
            break;
        case 3:
            double Withdrawval;
            cout << "Enter amount to be withdrawn " << endl;
            cin >> Withdrawval;
            if (Withdrawval > amount)
            {
                cout << "Not enough money" << endl;
            }
            else
                amount -= Withdrawval;
            break;
        default:
            break;
        }
    } while (option != 4);

    return 0;
}
