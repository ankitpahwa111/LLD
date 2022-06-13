#include <bits/stdc++.h>
using namespace std;

class Product{
    // keep them private and make getters and setters
    // we can also remove this model , we are keeping the maps in services
    public:
        string productId;
        string name;
        double price;
};

class Inventory{
    public:
        // map of productId vs quantity
        unordered_map<string,int>quantity;
        // map of productID vs Price
        unordered_map<string,double>prices;
        // map of productId vs Product Name
        unordered_map<string,string> names;
};

class InventoryService{
    public:
        Inventory inv;
        InventoryService(){
            inv.quantity["Aloo"] = 10;
            inv.quantity["Brinjal"] = 10;
            inv.quantity["Flour"] = 10;
            inv.quantity["Kinerjoy"] = 10;
            inv.quantity["Kheera"] = 10;
            inv.quantity["Tomato"] = 10;
            inv.quantity["Tori"] = 10;
            inv.quantity["Spinach"] = 10;
            inv.quantity["Sugar"] = 10;
            
            inv.prices["Aloo"] = 10.12;
            inv.prices["Brinjal"] = 1.12;
            inv.prices["Flour"] = 0.90;
            inv.prices["Kinerjoy"] = 10;
            inv.prices["Kheera"] = 10.99;
            inv.prices["Tomato"] = 10;
            inv.prices["Tori"] = 10.67;
            inv.prices["Spinach"] = 101;
            inv.prices["Sugar"] = 10;

            inv.names["Aloo"] = "Aloo";
            inv.names["Brinjal"] = "Brinjal";
            inv.names["Flour"] = "Flour";
            inv.names["Kinerjoy"] = "Kinerjoy";
            inv.names["Kheera"] = "Kheera";
            inv.names["Tomato"] = "Tomato";
            inv.names["Tori"] = "Tori";
            inv.names["Spinach"] = "Spinach";
            inv.names["Sugar"] = "Sugar";

        }
        bool addQty(string prodId, int qty){
            inv.quantity[prodId] += qty;
            cout<<"Qty added "<<endl;
            return true;
        }
        bool decreaseQty(string prodId, int qty){
            if(inv.quantity.count(prodId)==0){
                cout<<"Sorry this Product does not exist  "<<endl;
                return false;
            }
            if(inv.quantity[prodId]<qty){
                cout<<"Sorry the quantity cannot be subtracted !!  "<<endl;
                return false;
            }
            inv.quantity[prodId] -= qty;
            cout<<"Qty Decreased "<<endl;
            return true;
        }
        bool changePrice(string prodId, double price){
            if(inv.prices.count(prodId)==0){
                cout<<"The product does not exist "<<endl;
                return false;
            }
            inv.prices[prodId] = price;
            cout<<"Price changed "<<endl;
            return true;
        }
        void showProducts(){
            for(auto prod: inv.names){
                string prodId = prod.first;
                string prodName = prod.second;
                double price = inv.prices[prodId];
                cout<<prodId<<" "<<prodName<<" "<<price<<endl;
            }
        }
        int getQty(string prodId){
            if(inv.quantity.count(prodId)==1){
                return inv.quantity[prodId];
            }
            return 0;
        }
        double getPrice(string prodId){
            if(inv.prices.count(prodId)==1){
                return inv.prices[prodId];
            }
            return 0;
        }
};

class GroceryStore{
    InventoryService inventoryService;
    // CartService cartService;
     // map of productId vs quantity
    unordered_map<string, int> cart;
    double CartVal;
    public:
        GroceryStore(){
            this->CartVal = 0;
        }
        void showMenu(){
            this->inventoryService.showProducts();
        }
        void decreaseQty(string prodId, int qty){
            this->inventoryService.decreaseQty(prodId, qty);
        }
        void addQty(string prodId, int qty){
            this->inventoryService.addQty(prodId, qty);
        }
        void changePrice(string prodId, double price){
            this->inventoryService.changePrice(prodId, price);
        }
        void addToCart(string prodId, int qty){
            if(inventoryService.getQty(prodId)>=qty){
                cart[prodId] += qty;
                CartVal += inventoryService.getPrice(prodId) * qty;
                cout<<"Added to Cart !! Your Cart Value is "<<CartVal<<endl;
            }
            else{
                cout<<"Sorry this item is out of stock  "<<endl;
            }
        }

        void updateQtyIncart(string prodId, int qty){
            if(cart.count(prodId)==0){
                cout<<"Item not in cart  "<<endl;
                return;
            }
            cout<<"Updating cart :";
            CartVal -= inventoryService.getPrice(prodId) * cart[prodId];
            cart[prodId] = 0;
            addToCart(prodId, qty);
        }

        void removeFromcart(string prodId){
            if(cart.count(prodId)==0){
                cout<<"Item not in cart  "<<endl;
                return;
            }
            CartVal -= inventoryService.getPrice(prodId) * cart[prodId];
            cart.erase(prodId);
            cout<<"Item removed from Cart!!"<<endl;
        }

        void placeOrder(){
            cout<<"Placing order"<<endl;
            cout<<"--------------Thank you for your Order ------------------"<<endl;
            cout<<"Your Bill is "<<CartVal<<" Dollars :)"<<endl;
            cart.clear();
        }

};

int main(){
    GroceryStore gs;
    gs.showMenu();
    gs.addQty("Aloo",5);
    gs.decreaseQty("Brinjal",100);
    gs.changePrice("Aloo", 1.11);
    gs.addToCart("Aloo",10);
    gs.updateQtyIncart("Aloo",11);
    // gs.removeFromcart("Aloo");
    gs.placeOrder();
}