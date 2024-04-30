#include <windows.h>
#include "vector.h"
#include <stdexcept>
// #include <windows.h>
// #include "vector.h"
// #include <stdexcept>

using std::cout;
using std::endl;

int pass = 0;
int fail = 0;

bool assert_values(int* key, Vector vec) {
    bool failure = false;
    
    for (int k=0; k<vec.size(); k++) {
        if (vec[k] == key[k]) {pass++;} 
        else {
            failure = true;
            fail++;
        }
    }
    
    if (failure) {
        for (int k=0; k<vec.size(); k++) {
            cout << vec[k] << ' ' << key[k] << endl;
        }
    }

    return failure;
}

int main() {
    int valsOne[5] = {5, 4, 3, 2, 1};   
    int valsTwo[10] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int valsThree[5] = {0, 0, 0, 0, 0};
    int a;
    int b;
    int c;
    int d;
    bool e;
    cout << "start" << endl;
    
    try {
        Vector vecOne = Vector(5, valsOne); // testing initial constructor
        Vector vecTwo = Vector(10, valsTwo);
        Vector vecThree = Vector(5, valsThree);
        Vector vecFive = Vector();
        pass ++;
        
        if (!vecFive.empty()) {throw std::logic_error("Failure in key 0.5");}
        pass ++;
        
        int key1[5] = {5, 4, 3, 2, 1};
        if (assert_values(key1, vecOne)) {throw std::logic_error("Failure in key1");}
        
        // Vector vecFive = Vector(4, {3, 4, 5, 6}); //this don't work
        // cout << "One" << endl;
        
        
        Vector vecFour = vecOne; // testing copy constructors
        int key2[5] = {5, 4, 3, 2, 1};
        if (assert_values(key2, vecFour)) {throw std::logic_error("Failure in key2");}
        
        vecFour = vecTwo;
        int key3[10] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        if (assert_values(key3, vecFour)) {throw std::logic_error("Failure in key3");}
        // cout << "Two" << endl;
            
        a = vecOne.front();     //testing accessors
        b = vecOne.back();
        c = vecOne.at(2);
        d = vecOne.size();
        e = vecOne.empty();
            
        if (a!=5) {throw std::logic_error("Failure in key 3.1");}
        pass++;
        if (b!=1) {throw std::logic_error("Failure in key 3.2");}
        pass++;
        if (c!=3) {throw std::logic_error("Failure in key 3.3");}
        pass++;
        if (d!=5) {throw std::logic_error("Failure in key 3.4");}
        pass++;
        if (e) {throw std::logic_error("Failure in key 3.5");}
        pass++;
        
        // a = vecFive.front();     //testing accessors on the empty vector
        // b = vecFive.back();
        // c = vecFive.at(2); //no values so this errors out like it should
        d = vecFive.size();
        e = vecFive.empty();
        
        if (d!=0) {fail++; throw std::logic_error("Failure in key 3.6");}
        pass++;
        if (!e) {fail++; throw std::logic_error("Failure in key 3.7");}
        pass++;
        // cout << "Three" << endl;
        
        a = vecOne[3];          //Testing the [] accessor
        b = vecOne[6];  //garbage
        
        if (a!=2) {fail++; throw std::logic_error("Failure in key 3.6");}
            
        // cout << "Four" << endl;
        vecOne.push_back(8);        //testing push_back
        vecTwo.push_back(20);   //testing grow
        vecFive.push_back(2);
        
        int key4[6] = {5,4,3,2,1,8};
        if (assert_values(key4, vecOne)) {throw std::logic_error("Failure in key4");}
        
        int key5[11] = {6,7,8,9,10,11,12,13,14,15,20};
        if (assert_values(key5, vecTwo)) {throw std::logic_error("Failure in key5");}
        
        int key6[1] = {2};
        if (assert_values(key6, vecFive)) {throw std::logic_error("Failure in key6");}
        
        vecOne.pop_back();      //testing pop_back
        vecFive.pop_back();
        
        int key7[5] = {5,4,3,2,1};
        if (assert_values(key7, vecOne)) {throw std::logic_error("Failure in key7");}
        
        if (!vecFive.empty()) {fail++; throw std::logic_error("Failure in key 7.5");}
        pass++;
        
        vecOne.erase(1);        //testing erase
        vecTwo.erase(6);
        
        int key8[4] = {5,3,2,1};
        if (assert_values(key8, vecOne)) {throw std::logic_error("Failure in key8");}
        
        int key9[10] = {6,7,8,9,10,11,13,14,15,20};
        if (assert_values(key9, vecTwo)) {throw std::logic_error("Failure in key9");}
        
        // vecFive.erase(0); // empty vector errors out like it should
        
        vecOne.insert(1, 9);    //testing insert
        vecFour.insert(5, 3);   //using grow
        
        int key10[5] = {5,9,3,2,1};
        if (assert_values(key10, vecOne)) {throw std::logic_error("Failure in key10");}
        
        int key11[11] = {6,7,8,9,10,3,11,12,13,14,15};
        if (assert_values(key11, vecFour)) {throw std::logic_error("Failure in key11");}
        
        int key12[5] = {0,0,0,0,0};
        if (assert_values(key12, vecThree)) {throw std::logic_error("Failure in key12");}
        
        vecThree.clear();       //testing clear
        if (!vecThree.empty()) {fail++; throw std::logic_error("Failure in key 12.5");}
        pass++;
        
        int* q = vecOne.begin(); // testing iterators - adding one to every value then subtracting 2 to every value
        for (int i=0; i<vecOne.size(); i++) {
            *(q+i) += 1;
        }
        
        int key13[5] = {6,10,4,3,2};
        if (assert_values(key13, vecOne)) {throw std::logic_error("Failure in key13");}
        pass++;
        
        q = vecOne.end();
        for (int i=0; i<vecOne.size(); i++) {
            *(q-i) -= 2;
        }
        
        int key14[5] = {4,8,2,1,0};
        if (assert_values(key14, vecOne)) {throw std::logic_error("Failure in key14");}
        
        Vector vecSix = Vector(5, valsOne);
        vecThree = vecOne;      
        
        e = (vecThree == vecOne);       // testing == and != operators
        if (!e) {fail++; throw std::logic_error("Failure in key 14.1");} 
        pass++;
        e = (vecTwo == vecOne);
        if (e) {fail++; throw std::logic_error("Failure in key 14.2");}
        pass++;
        e = (vecSix == vecOne);
        if (e) {fail++; throw std::logic_error("Failure in key 14.3");}
        pass++;
        
        e = (vecThree != vecOne);
        if (e) {fail++; throw std::logic_error("Failure in key 14.4");}
        pass++;
        e = (vecTwo != vecOne);
        if (!e) {fail++; throw std::logic_error("Failure in key 14.5");}
        pass++;
        e = (vecSix != vecOne);
        if (!e) {fail++; throw std::logic_error("Failure in key 14.6");}
        pass++;
                
        
    } catch (std::logic_error& exc) {
        cout << exc.what()  << endl;
    } catch(std::range_error& exc) {
        cout << exc.what()  << endl;
    }
    
    cout << "Test Report:" << endl
         << "   Number of Passes: " << pass << endl
         << "   Number of Failures: " << fail << endl;
    return 0;
}