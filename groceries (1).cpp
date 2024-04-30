#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "split.h"
// #include "customers.txt"
// #include "items.txt" 


using namespace std;

//classes
class Customer {
public:
    static int customer_count;
    int customer_id;
    string name;
    string street;
    string city;
    string state;
    string zip;
    string phone;
    string email;

};

class Item {
public:
    static int item_count;
    int item_id;
    string description;
    double price;
};

class Order {
public:
    int customer_id;
    Customer* current_customer;
    vector<Item*> items;
    double total_price;

    Order() {
        customer_id = 0;
    }

    void add_to_order(Item* p_item) {
        items.push_back(p_item);
        total_price += p_item->price;
        cout << '$' << p_item->price << ' ' << p_item->description << " added to cart" << endl;
    }

    void print_total() {
        cout << "Your total for " << items.size() << " items is $" << total_price << endl;
        cout << "Thank you for shopping at Big Pharma >:)" << endl;
    }
};

//global vectors
vector<Customer*> all_customers;
vector<Item*> all_items;
int customer_count = 0;
int item_count = 0;

//functions

//I could use a template for these two functions, I would just have to pass in the global vectors as parameters
Item* find_item_idx (int id) {
    int k = all_items.size();
    Item* j;

    for (int i=0; i<=k-1; i++ ) {
        j = all_items[i];
        if (j->item_id == id) {return j;} 
        else {j = nullptr;}
    }

    cout << "Item not found." << endl;
    throw domain_error("");
    return j;
    
}

Customer* find_customer_idx(int id) {
    int k = all_customers.size();
    Customer* j;
    
    for (int i=0; i<=k-1; i++ ) {
        j = all_customers[i];
        if (j->customer_id == id) {return j;}
    }

    cout << "Customer not found. " << endl;
    throw domain_error("");
    return j;
}

void read_customers(string c_file) {
    fstream newfile;
    newfile.open(c_file, ios::in); 
    string line;
    vector<string> cust_fields;
    int num_cust=0;
    Customer();

    if (newfile.is_open()) {
        while (getline(newfile, line)) { ;
            Customer* cust_ptr = new Customer();
            all_customers.push_back(cust_ptr);
            cust_fields = split(line, ',');
            
            all_customers[num_cust]->customer_id = stoi(cust_fields[0]);
            all_customers[num_cust]->name = cust_fields[1];
            all_customers[num_cust]->street = cust_fields[2];
            all_customers[num_cust]->city = cust_fields[3];
            all_customers[num_cust]->state = cust_fields[4];
            all_customers[num_cust]->zip = cust_fields[5];
            all_customers[num_cust]->phone = cust_fields[6];
            all_customers[num_cust]->email = cust_fields[7];

            num_cust++;
            // Customer().customer_count ++;
            //cout << line << "\n"; 
        }
    }
    customer_count = num_cust;
}

void read_items(string i_file) {
    fstream newfile;
    newfile.open(i_file, ios::in); 
    string line;
    vector<string> item_fields;
    int num_item=0;

    if (newfile.is_open()) {
        while (getline(newfile, line)) { ;
            Item* item_ptr = new Item();
            all_items.push_back(item_ptr);
            item_fields = split(line, ',');
            
            all_items[num_item]->item_id = stoi(item_fields[0]);
            all_items[num_item]->description = item_fields[1];
            all_items[num_item]->price = stod(item_fields[2]);

            num_item++;
            // Item().item_count ++;
            //cout << line << "\n"; 
        }
    }
    
    item_count = num_item;
}

void display_introduction () {
    Customer();
    cout << "Welcome! There are " << customer_count << " customers and " 
        << item_count << " items" << endl;
}

void one_customer_order () {
    display_introduction();

    try {
        int curr_cust_id;
        cout << "Enter a customer id: " << endl;
        cin >> curr_cust_id;

        Order* current_order = new Order();
        current_order->customer_id = curr_cust_id;
        current_order->current_customer = find_customer_idx(curr_cust_id);
        cout << "Welcome " << current_order->current_customer->name << endl;

        int input_id;
        Item* item_ptr;

        while (true) {
            cout << "Enter an item id to add to your order: " << endl;
            cin >> input_id;
            if (input_id == 0) {break;};

            item_ptr = find_item_idx(input_id);
            // if (item_ptr->price == 0) {cout << "Item not found. " << endl;}
            current_order->add_to_order(item_ptr);
        } 

        current_order->print_total();

    } catch (domain_error& exc) {
        cout << exc.what() << endl;
    } catch (ios_base::failure& exc) {
        cout << exc.what() << endl;
        cout << "stream exception thrown." << endl;
    } catch (runtime_error& exc) {
        cout << exc.what() << endl;
        cout << "runtime exception thrown." << endl;
    } catch (exception& exc) {
        cout << exc.what() << endl;
        cout << "other exception thrown." << endl;
    }
}

int main () {
    read_customers("customers.txt");
    read_items("items.txt");
    one_customer_order();
    // cout << "done";
    return 0;
}  