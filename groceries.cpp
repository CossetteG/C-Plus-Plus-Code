#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <algorithm>
#include "split.h"
// #include "customers.txt"
// #include "items.txt" 
// #include "Orders.txt"

using namespace std;

//Section 1 - customers
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

vector<Customer*> all_customers;
// int customer_count = 0;

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
    // Customer.customer_count = num_cust;
}

//section 2- items
class Item {
public:
    static int item_count;
    int item_id;
    string description;
    double price;
};

class LineItem  : public Item {
public:
    int qty;
    double effective_price;

    LineItem (Item* item, int quantity) {
        item_id = item->item_id;
        description = item->description;
        price = item->price;
        qty = quantity;
        effective_price = price * quantity;
    }
};

vector<Item*> all_items;
// int item_count = 0;


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
}

//Section 3- Payments
class Payment {
public:
    int method;
    string payprint;
    double amount;
};

class Credit : public Payment{
public:
    string cc_number;
    string exp;
    Credit (int paymethod, string cc_num, string expire) {
        method = paymethod;
        cc_number = cc_num;
        exp = expire;
        payprint = "Credit card " + cc_number + ", exp." + exp;
    }
};

class PayPal : public Payment {
public:
    string user;
    PayPal(int paymethod, string usern) {
        method = paymethod;
        user = usern;
        payprint = "Paypal ID: " + user;
    }
};

class WireTransfer : public Payment {
public:
    string bank_id;
    string account_id;
    WireTransfer(int paymethod, string banknum, string accnum) {
        method = paymethod;
        bank_id = banknum;
        account_id = accnum;
        payprint = "Wire transfer from Bank ID " + bank_id + ", Account #" + account_id;
    }
};


//Section 4- Orders
class Order {
public:
    Customer* current_customer;
    int order_number;
    Payment* pay;
    string date;

    vector<LineItem*> items;
    double total_price;


    Order(Customer* person, int ordernum, string curr_date, Payment* paym) {
        current_customer = person;
        order_number = ordernum;
        date = curr_date;
        pay = paym;
    }

    ~Order() {
        delete[] (current_customer);
        delete[] (pay);
    }

    void add_to_order(LineItem* p_item) {
        items.push_back(p_item);
        total_price += p_item->effective_price;
        // cout << '$' << p_item->price << ' ' << p_item->description << " added to cart" << endl;
    }

    string total(double num, int precision) {
        string bean;
        string finished;
        bool countdown = false;
        bean = to_string(num);
        int j = precision;

        for (int i=0; i<bean.length(); i++) {
            if (j >= 0) {finished += bean.at(i);}
            if (bean.at(i) == '.') {countdown = true;}
            if (countdown) {j--;}
        }
        return finished;
    }


    string print_order() {
        string ordertxt;

        ordertxt = "===========================\n";
        ordertxt += "Order #" + to_string(order_number); 
        ordertxt += ", Date: " + date + '\n';
        ordertxt += "Amount: " + total(total_price, 2) + ", Paid by " + pay->payprint + '\n' + '\n';
        ordertxt += "Customer ID #" + to_string(current_customer->customer_id) ;
        ordertxt += ", ph. " + current_customer->phone + " email: " ;
        ordertxt += current_customer->email + '\n' + current_customer->street + '\n';
        ordertxt += current_customer->city + ", " + current_customer->state + ' ' + current_customer->zip + '\n' + '\n';
        ordertxt +=  "Order Detail:\n";

        sort(items.begin(), items.end(), [](LineItem* i, LineItem* j){return i->item_id < j->item_id;});

        for (int i=0; i<items.size(); i++) {
            LineItem* iptr = items[i];
            ordertxt += "   Item ";
            ordertxt += to_string(iptr->item_id);
            ordertxt += ": " + iptr->description ;
            ordertxt += ", ";
            ordertxt += to_string(iptr->qty); 
            ordertxt += " @ " ;
            ordertxt += total(iptr->price, 2);
            ordertxt += '\n';
        }

        return ordertxt;
    }
};

list<Order*> orders;

void read_orders(string i_file) {
    fstream newfile;
    newfile.open(i_file, ios::in); 
    string line;

    int num_order=0;
    bool payment = false;

    vector<string> order_fields;
    Customer* curr_cust;
    int c_id;
    int o_num;
    string o_date;

    vector<string> payment_fields;
    int pmethod;
    string pdet1;
    string pdet2;

    vector<string> item_fields;

    if (newfile.is_open()) {
        while (getline(newfile, line)) {
            if (!payment) {
                order_fields = split(line, ',');
                payment = true;
            } else {
                c_id = stoi(order_fields[0]);
                o_num = stoi(order_fields[1]); //2
                o_date = order_fields[2];   //3
                Customer* custptr = find_customer_idx(c_id); //1

                payment_fields = split(line, ',');
                pmethod = stoi(payment_fields[0]); 
                Payment* payptr;
                if (pmethod == 1) {     //4
                    payptr = new Credit(pmethod, payment_fields[1], payment_fields[2]);
                } else if (pmethod == 2) {
                    payptr = new PayPal(pmethod, payment_fields[1]);
                } else if (pmethod == 3) {
                    payptr = new WireTransfer(pmethod, payment_fields[1], payment_fields[2]);
                } else {throw runtime_error("theif! catch him!");}


                Order* order_ptr = new Order(custptr, o_num, o_date, payptr);
                payptr->amount = order_ptr->total_price;
                orders.push_back(order_ptr);

                for (int i = 3; i < order_fields.size(); i++) {
                    item_fields = split(order_fields[i], '-');
                    LineItem* litemptr = new LineItem(find_item_idx(stoi(item_fields[0])), stoi(item_fields[1]));
                    order_ptr->add_to_order(litemptr);
                }

                // cout << order_ptr->current_customer->name << endl;

                num_order++;
                payment = false;
            }
        }
    }
}


int main() {
    read_customers("customers.txt");
    read_items("items.txt");
    read_orders("orders.txt");

    ofstream ofs("order_report.txt");
    for (const auto& order: orders) {
        ofs << order->print_order() << endl;
    }
    // I changed the fuction call to work with my code better 
    cout << "done" << endl; 
}


// void display_introduction () {
//     Customer();
//     cout << "Welcome! There are " << customer_count << " customers and " 
//         << item_count << " items" << endl;
// }

/*
void one_customer_order () {
    display_introduction();

    try {
        int curr_cust_id;
        cout << "Enter a customer id: " << endl;
        cin >> curr_cust_id;

        Order* current_order = new Order(find_customer_idx(curr_cust_id));
        
        cout << "Welcome " << current_order->current_customer->name << endl;

        int input_id;
        Item* item_ptr;

        while (true) {
            cout << "Enter an item id to add to your order: " << endl;
            cin >> input_id;
            if (input_id == 0) {break;};

            item_ptr = find_item_idx(input_id);
            if (item_ptr->price == 0) {cout << "Item not found. " << endl;}
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
*/