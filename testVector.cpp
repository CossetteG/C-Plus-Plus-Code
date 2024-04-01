#include <iostream>
#include <windows.h>
#include "vector.h"
using std::cout;
using std::endl;
#include <stdexcept>

int pass = 0;
int fail = 0;

void assert_values(int* key, Vector vec) {
    for (int k=0; k<vec.size(); k++) {
        assert(vec[k] == key[k]);
        pass++;
    }
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

    //using nested try-catch blocks
    try {
        Vector vecOne = Vector(5, valsOne); // testing initial constructor
        Vector vecTwo = Vector(10, valsTwo);
        Vector vecThree = Vector(5, valsThree);
        Vector vecFive = Vector();
        pass += 1;
        
        assert (vecFive.empty());
        pass ++;
        
        int key1[5] = {5, 4, 3, 2, 1};
        assert_values(key1, vecOne);
        
        // Vector vecFive = Vector(4, {3, 4, 5, 6}); //this don't work
        cout << "One" << endl;
        
        try {
            Vector vecFour = vecOne; // testing copy constructors
            int key2[5] = {5, 4, 3, 2, 1};
            assert_values(key2, vecFour);
            
            vecFour = vecTwo;
            int key3[10] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
            assert_values(key3, vecFour);
            cout << "Two" << endl;
            
            try {
                a = vecOne.front();     //testing accessors
                b = vecOne.back();
                c = vecOne.at(2);
                d = vecOne.size();
                e = vecOne.empty();
                    
                assert(a==5);
                pass++;
                assert(b==1);
                pass++;
                assert(c==3); //ha
                pass++;
                assert(d==5);
                pass++;
                assert(e==false);
                pass++;
                
                // a = vecFive.front();     //testing accessors on the empty vector
                // b = vecFive.back();
                // c = vecFive.at(2); //no values so this errors out like it should
                d = vecFive.size();
                e = vecFive.empty();
                
                assert(d==0);
                pass++;
                assert(e==true);
                pass++;
                cout << "Three" << endl;
            
            }catch (std::logic_error& exc) {
            cout << exc.what() << "Failure in accessors test" << endl;
            fail += 1;
            }
        }catch (std::logic_error& exc) {
        cout << exc.what() << "Failure in copy constructor test" << endl;
        fail += 1;
        }
    } catch (std::logic_error& exc) {
        cout << exc.what() << "Failure in constructor test" << endl;
        fail += 1;
    }

    Vector vecOne = Vector(5, valsOne); //my test Vectors fell out of scope so I need new ones so I don't nest a bajillion try blocks
    Vector vecTwo = Vector(10, valsTwo);
    Vector vecThree = Vector(5, valsThree);
    Vector vecFive = Vector();
    Vector vecFour = vecTwo;
    cout << "Four" << endl;
    
    a = vecOne[3];          //Testing the [] accessor
    b = vecOne[6];  //garbage
    c = vecFive[0]; //garbage
    cout << a << ' ' << b << ' ' << c << ' ' << endl;
    /*
    Output:
    2 0 0
    */
    
    vecOne.push_back(8);        //testing push_back
    vecTwo.push_back(20);   //testing grow
    vecFive.push_back(2);
    vecOne.see_values();
    vecTwo.see_values();
    vecFive.see_values();
     /*
    Output:
    5 4 3 2 1 8 
    6 7 8 9 10 11 12 13 14 15 20 
    2 
    */ 
    
    vecOne.pop_back();      //testing pop_back
    vecFive.pop_back();
    vecOne.see_values();
    vecFive.see_values();
    /*
    Output:
    5 4 3 2 1 

    */ 
    
    vecOne.erase(1);        //testing erase
    vecTwo.erase(6);
    vecOne.see_values();
    vecTwo.see_values();
    // vecFive.erase(0); // empty vector errors out like it should
    /*
    Output:
    5 3 2 1 
    6 7 8 9 10 11 13 14 15 20 
    */ 
    
    vecOne.insert(1, 9);    //testing insert
    vecFour.insert(5, 3);   //using grow
    vecOne.see_values();
    vecFour.see_values();
    /*
    Output:
    5 9 3 2 1 
    6 7 8 9 10 3 11 12 13 14 15 
    */ 
    
    vecThree.see_values();      //testing clear
    vecThree.clear();
    vecThree.see_values();
    /*
    Output:
    0 0 0 0 0 

    */ 
    
    vecOne.see_values();
    int* q = vecOne.begin(); // testing iterators - adding one to every value then subtracting 2 to every value
    for (int i=0; i<vecOne.size(); i++) {
        *(q+i) += 1;
    }
    vecOne.see_values();
    
    q = vecOne.end();
    for (int i=0; i<vecOne.size(); i++) {
        *(q-i) -= 2;
    }
    vecOne.see_values();
    /*
    Output:
    5 9 3 2 1 
    6 10 4 3 2 
    4 8 2 1 0 
    */ 
    
    Vector vecSix = Vector(5, valsOne);
    vecThree = vecOne;      
    e = (vecThree == vecOne);       // testing == and != operators
    cout << e << ' '; //true
    e = (vecTwo == vecOne);
    cout << e << ' '; //false
    e = (vecSix == vecOne);
    cout << e << ' '; //false
    
    e = (vecThree != vecOne);
    cout << e << ' '; //false
    e = (vecTwo != vecOne);
    cout << e << ' '; //true
    e = (vecSix != vecOne);
    cout << e << ' ' << endl; //true
   /*
    Output:
    1 0 0 0 1 1 
    */ 
    
    cout << "done" << endl;
    return 0;
}