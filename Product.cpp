// Product class
#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Product {
public:
    string name;
    float price;
    int quantity;

    Product(string name, float price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};
