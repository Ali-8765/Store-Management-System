#include <iostream>
#include <string>
#include <vector>
#include "Customer.cpp"

using namespace std;

// Employee class
class Employee {
private:
    Store& store;

public:
    Employee(Store *store) : store(*store) {
        this->store = *store;
    }

    void refill_stock(string product_name, int quantity) {
        store.refill_stock(product_name, quantity);
    }

    vector<Product*>& view_products() {
        return store.view_products();
    }
    
    void add_product(Product *product) {
     store.add_product(product);
}

};