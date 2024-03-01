#include <iostream>
#include <string>
#include <vector>
#include "Store.cpp"

using namespace std;


// Customer class
class Customer {
private:
    Store& store;

public:
    Customer(Store *store) : store(*store) {
        this->store = *store;
    }

    float purchase(string product_name, int quantityneg) {
        vector<Product*>& products = store.view_products();
        for (int i = 0; i < products.size(); i++) {
            if ((*products[i]).name == product_name) {
                if ((*products[i]).quantity < quantityneg) {
                    cout << "Not enough stock!" << endl;
                    return 0.0;
                }
                (*products[i]).quantity=(*products[i]).quantity - quantityneg;
                return (*products[i]).price * quantityneg;
            }
        }
        cout << "Product not found!" << endl;
        return 0.0;
    }

    vector<Product*>& view_products() {
        return store.view_products();
    }
   
};