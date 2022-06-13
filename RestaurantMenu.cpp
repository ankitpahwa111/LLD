// Second problem was designing Restaurant menu which contains dishes and each dish has a name, price and list of ingredients its made up of. 
// There were 6 functionalities which were expected from me to be implemented -

// Add a dish to restaurant menu
// Remove a dish from restaurant menu
// Add an ingredient to a dish
// Given a list of dishes ordered, return the total amount of bill taking in account tax.
// Given an ingredient, return the list of all the dishes containing that ingredient.
// Return all the dishes served in a restaurant.

#include <bits/stdc++.h>
#define ACCOUNT_TAX_PERCENT 10
using namespace std;

class Dish
{
    string name; // unique name
    double price;

public:
    list<string> ingredients;
    Dish()
    {
    }
    Dish(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
    string getName() { return this->name; }
    double getPrice() { return this->price; }
    // list<string> getIngredients() { return this->ingredients };
};

class MenuService
{
    unordered_map<string, list<Dish>> DishesHavingIngredient;
    unordered_map<string, Dish> menu;
    // int DEFAULT_ACCOUNT_TAX_PERCENT;
public:
    // MenuService(){
    //     this->DEFAULT_ACCOUNT_TAX_PERCENT = 10;
    // }
    void addDish(string name, double price)
    {
        if (menu.count(name) == 1)
        {
            cout << "DIsh Already exists " << endl;
            return;
        }
        Dish newDish(name, price);
        menu[name] = newDish;
        cout << "DIsh added to the menu :) " << endl;
    }

    void removeDish(string name)
    {
        if (menu.count(name) == 0)
        {
            cout << "Dish does not exist in the menu " << endl;
            return;
        }
        menu.erase(name);
        cout << "DIsh has been removed  the menu :) " << endl;
    }

    void addIngredientToDish(string name, string ingredient)
    {
        if (menu.count(name) == 0)
        {
            cout << "Dish does not exist in the menu " << endl;
            return;
        }
        for (auto ing : menu[name].ingredients)
        {
            if (ing == ingredient)
            {
                cout << "Ingredient already exist in the dish " << endl;
                return;
            }
        }
        menu[name].ingredients.push_back(ingredient);
        if (DishesHavingIngredient.count(ingredient) == 0)
        {
            list<Dish> l;
            DishesHavingIngredient[ingredient] = l;
        }
        DishesHavingIngredient[ingredient].push_back(menu[name]);
        cout << "The ingredient has been addded to the dish :) " << endl;
    }
    void showDishesWithIngredient(string ing)
    {
        if (DishesHavingIngredient.count(ing) == 0)
        {
            cout << "No dish has " << ing << endl;
            return;
        }
        cout << "Dishes having " << ing << " are :" << endl;
        for (auto dish : DishesHavingIngredient[ing])
        {
            cout << dish.getName() << endl;
        }
        return;
    }
    void showAllDishesinMenu()
    {
        cout << "Welcome !! We have following dishes " << endl;
        for (auto dish : menu)
        {
            cout << dish.second.getName() << " " << dish.second.getPrice()<<endl;
        }
    }
    double placeOrder(Dish dish){
        if(menu.count(dish.getName())==0){
            return -1;
        }
        return dish.getPrice();
    }
    void orderDishes(list<string> dishesOrdered){
        cout<<"Placing Order "<<endl;
        double totalValue = 0;
        for(auto dish : dishesOrdered){
            int dishVal = placeOrder(menu[dish]);
            if(dishVal == -1){
                cout<<"Sorry We dont have "<<dish<<endl;
            }
            else{
                totalValue += dishVal;
            }
        }
        totalValue += (ACCOUNT_TAX_PERCENT*totalValue)/100;
        cout<<"Order Placed :) , Your Bill is "<<totalValue<<endl;
        cout<<"Happy To Serve "<<endl;
    }
};

int main()
{
    MenuService restaurant;
    restaurant.addDish("Aloo Paratha", 100);
    restaurant.addDish("Aloo Paratha", 100);
    restaurant.addIngredientToDish("Aloo Paratha", "Namak");
    restaurant.showDishesWithIngredient("Namak");
    restaurant.showAllDishesinMenu();
    restaurant.addDish("Gobhi Paratha", 100);
    restaurant.showAllDishesinMenu();
    list<string> dishes = {"Aloo Paratha", "Gobhi Paratha", "Mooli Paratha"};
    restaurant.orderDishes(dishes);
    // restaurant.removeDish("Aloo Paratha");
}