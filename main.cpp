#include <iostream>
#include <cstdio>
#include <string>
#include<conio.h>
#include<limits>
#include <vector>
#include<fstream>
#include "Dealer.cpp"

string convertToString(char* a)
{
    string s(a);
 return s;
}

using namespace std;
void login(Store *store, Dealer *dealer, Employee *employee,Customer *customer);
int test();
float testf();

int main() 
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO THE DREAM SHOP ============|";
	getch();
	system("cls");
	
   Store *store = new Store();
    Dealer *dealer = new Dealer(store);
    Employee *employee = new Employee(store);
    Customer *customer = new Customer(store);
      ifstream input("vector.txt");
    string name;
    double price;
    int quantity;
    while(input>>name>>price>>quantity){
        Product *product=new Product(name, price, quantity);
        dealer->add_product(product);
    }
    input.close();
login(store, dealer, employee, customer);
ofstream output("vector.txt");
 vector<Product*>& products= dealer->view_products();
 for(int i=0;i<products.size();i++){
    output<<(*products[i]).name<<" "<<(*products[i]).price<<" "<<(*products[i]).quantity<<endl;
 }
 output.close();
    delete customer;
    delete employee;
    delete dealer;
    delete store;
    return 0;
}



// Login function
void login(Store *store, Dealer *dealer, Employee *employee,Customer *customer)   {
    char pin[100];
    string username;
    int k=0;
    string password;
    start: 
   
    cout<<"\n\t\t   STORE MANAGEMENT SYSTEM\n";	
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1.Login\n\n\t\t   2.Save & Quit";
    cout<<"\n\n\t== Don't forget to quit to save your work =="<<endl;
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
   
    
    
      int choice=test();
    
        switch (choice) {
        case 1:
        {  
    pin[100]={0};
    k=0;
     username=" ";
    password=" ";

    cout << "Enter username: ";
    
    cin.ignore();
    cin >> username;

    cout << "Enter password: ";

     while(pin[k-1]!='\r') {
        fflush(stdin);
        pin[k]=getch();
        if(pin[k-1]!='\r') {
            cout<<"*";
        }
        k++;
    }
    pin[k-1]='\0';
    cout<<endl; 
    
    
    
    /*cin.ignore();
    cin >> password;
   */
   password=convertToString(pin);


   
    

    // Check if the username and password match a dealer's credentials
    if (username == "dealer" && password == "dealer123") {
        loop1:
        system("cls");
        // Dealers can add products and refill stock
        cout<<"=================================================================";
	cout<<"\n\n\t\t\t    Welcome, Dealer!\n1.Add new product\n2.Remove product\n3.Refill\n4.View products\n5.Back";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice:  ";
       
        int choice = test();
        
        switch (choice) {
        case 1: { 
	        system("cls");
            cout << "Enter product name: ";
            string product_name;
            fflush(stdin);
            getline(cin, product_name);
            cout << "Enter product price: ";
            float price = testf();
            
            cout << "Enter product quantity: ";
            int quantity= test();
            Product *product= new Product(product_name, price, quantity);
            dealer->add_product(product);
            
            break;
        }
        case 2: {
	         system("cls");
             cout << "Enter product name: ";
             string name;
            fflush(stdin);
            getline(cin, name);
            store->remove_product(name);
            break;

        }
        case 3: {
	        system("cls");
            cout << "Enter product name: ";
            string product_name;
            fflush(stdin);
            getline(cin, product_name);
            cout << "Enter quantity: ";
            int quantity= test();
           
            dealer->refill_stock(product_name, quantity);
            break;
        }
        case 4: {
	        system("cls");
            vector<Product*>& products = employee->view_products();
            cout<<"name price quantity"<<endl;
            
            for (int i = 0; i < products.size(); i++) {
                cout << (*products[i]).name << " " << (*products[i]).price << " " << (*products[i]).quantity << endl;
            }
            _getch();
	        system("cls");
            break;
        }
        case 5:{
        system("cls");
        goto start;
        fflush(stdin);
        }

        default:
            cout << "Invalid choice!" << endl;
             _getch();
	         system("cls");
            break;
        }
        goto loop1;
    }
    // Check if the username and password match an employee's credentials
    else if (username == "employee" && password == "employee456") {
        loop2:
        system("cls");

        // Employees can refill stock and view products
           cout<<"=================================================================";
	cout<<"\n\n\t\t\t    Welcome, Employee!\n1.Refill\n2.View product\n3.Back";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
        
    
        int choice= test();
                
        switch (choice) {
        case 1: {
            system("cls");
            cout << "Enter product name: ";
            string product_name;
            fflush(stdin);
            getline(cin, product_name);
            cout << "Enter quantity: ";
            int quantity= test();
            
            employee->refill_stock(product_name, quantity);
            break;
        }
        case 2: {
            cout<<"name price quantity"<<endl;
            vector<Product*>& products = employee->view_products();
            
            for (int i = 0; i < products.size(); i++) {
                cout << (*products[i]).name << " " << (*products[i]).price << " " << (*products[i]).quantity << endl;
            }
             _getch();
	        system("cls");
            break;
        }
        case 3:
        system("cls");
        goto start;
        default:
            cout << "Invalid choice!" << endl;
             _getch();
	        system("cls");
            break;
        }
        goto loop2;
    }
    // Check if the username and password match a customer's credentials
    else if (username == "customer" && password == "customer789") {
        loop3:
        system("cls");
        // Customers can purchase products and view products
           cout<<"=================================================================";
	cout<<"\n\n\t\t\t    Welcome, Customer!\n1.Purchase product\n2.View products\n3.Back";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
       
        int choice= test();
       
        switch (choice) {
        case 1: {
            system("cls");
            cout << "Enter product name: ";
            string product_name;
            fflush(stdin);
            getline(cin, product_name);
            cout << "Enter quantity: ";
            int quantityneg= test();
           
            float total_cost = customer->purchase(product_name, quantityneg);
            cout << "Total cost: " << total_cost << endl;
             _getch();
	         system("cls");
            break;
        }
        case 2: {
            system("cls");
            cout<<"name price quantity"<<endl;
            vector<Product*>& products = customer->view_products();
            
            for (int i = 0; i < products.size(); i++) {
                cout << (*products[i]).name << " " << (*products[i]).price << " " << (*products[i]).quantity << endl;
            }
             _getch();
	         system("cls");
            break;
        }
        case 3:
        goto start;
        default:
            cout << "Invalid choice!" << endl;
             _getch();
	         system("cls");
            break;
        }
        system("cls");
        goto loop3;
    }
    // If the username and password don't match any known credentials
    else {
        cout << "Invalid username or password!" << endl;
         _getch();
	    system("cls");
    }
    goto start;
        }
         case 2:
         { 
         cout<<"\n\n\n";
         cout<<"           \t\tThanks for coming to our store! :p"<<endl;
         cout<<"Jawad(5887)"<<"\t\t\t"<<"2023 (c)"<<"\t\t\t"<<"Ali(6028)"<<"\n\n"<<endl;
          system("pause");
         return ;}
        default:{
            cout << "Invalid choice..." "Try again:!" << endl;
        }
        goto start;
        }
}
int test (){
    int x;
     while(!(cin >> x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input..." "USE NUMBERS"<<endl ;
        cout << "Try again:"<<endl ;
    }
    return x;

}
float testf (){
    float x;
     while(!(cin >> x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input..." "Try again:"<<endl ;
    }
    return x;

}