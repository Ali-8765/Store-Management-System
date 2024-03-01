// Dealer class
#include <iostream>
#include <string>
#include <vector>
#include "Employee.cpp"
using namespace std;



class Dealer : public Employee  {
private:
Store& store;
public:
    Dealer(Store *store) : store(*store), Employee(store) {}

    void add_product(Product *product) {
        Employee::add_product(product);
    }
  
};