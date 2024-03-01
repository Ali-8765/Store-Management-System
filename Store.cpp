#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<limits>
#include "Product.cpp"
using namespace std;


// Store class
class Store {
private:
    vector<Product*> products;

public:
    ~Store() {
    for (int i = 0; i < products.size(); i++) {
        delete products[i];
    }
}

    void add_product(Product *product) {
        int y=0;
        for(int i=0;i<products.size();i++)
                if(products[i]->name == product->name && products[i]->price == product->price){
                    y++;

                }
            
        if(y==0){
        products.push_back(product);
        }else
            refill_stock(product->name,product->quantity);
            }
            
void remove_product(string product_name) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i]->name == product_name) {
                int z;
                cout <<"are you sure you want to delete:"<<products[i]->name<<" ?"<< endl;
                cout <<"quantity: "<<products[i]->quantity<< endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "Enter your choice: " << endl;
                 while(!(cin >> z)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input..." "Try again:"<<endl ;
                          }
                
                
                switch (z) {
        case 1:
        { products.erase(products.begin() + i);
                return; }
        case 2: 
        {
         return;   
        }      
                
                
                }
                
            }
        }
    }
    /*
    void remove_product(string product_name) {
        int z=0;
        
        int y=0;  
        int i=0;
       
        for ( i=0  ; i < products.size(); i++) {
        if (products[i]->name == product_name)
        {y=5;
        }
            }
        if(y == 5){
        
        cout <<"are you sure you want to delete:"<<products[i]->name<<" ?"<< endl;
        cout <<"quantity: "<<products[i]->quantity<< endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter your choice: " << endl;

        while(!(cin >> z)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input..." "Try again:"<<endl ;
    }
   
      switch (z) {
        case 1:
        {  
            delete products[i];
            products.erase(products.begin() + i);
            return ;
            break;
             }
             
        case 2:
            {
                
                return;
            }
            
    }
            }else{
                cout<<"no such product exist choose 4 to view products"<<endl;
                return;

            }
            }*/
    


    vector<Product*>& view_products() {    
    return products;
}

    void refill_stock(string product_name, int quantity) {
        for (int i = 0; i < products.size(); i++) {
            if ((*products[i]).name == product_name) {
                (*products[i]).quantity += quantity;
                return;
            }
            
        }return;
        
    }
};
