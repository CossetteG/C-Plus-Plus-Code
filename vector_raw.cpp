/* this is the raw file as I wrote and tested in JDoodle because Visual Studio Code hates my 
computer. As you can see, it can very easily be split into vector.h and vector.cpp. The testing 
in this is not set up according to the rubric becuase I was also using it to make sure my vector
had the correct values in it and not just that it didn't throw an error. 
*/
// #ifndef VECTOR_H
// #define VECTOR_H
 
#include <cstddef>
#include <iostream>
#include <cassert>
using std::size_t;
using std::cout;
using std::endl;

class Vector {
    enum {CHUNK = 10};
    int* data_ptr;
    // Pointer to the heap array
    size_t capacity;
    // Size of the current array allocation (total number of ints)
    size_t n_elems;
    // Number of int spaces currently in use, starting from pos 0
    void grow() {
        capacity += CHUNK;
        int* new_data_ptr = new int[capacity];
        
        for (int i=0; i<capacity; i++) {
            if (i>=n_elems) {new_data_ptr[i] = 0;}
            else {new_data_ptr[i] = data_ptr[i];}
            
        }
        
        data_ptr = new_data_ptr;
        
        // delete new_data_ptr;
        // new_data_ptr = nullptr;
    };
public:
    // Object Mgt.
    Vector() {              //default
        data_ptr = new int[CHUNK];
        capacity = CHUNK;
        n_elems = 0;
    }; 
    
    Vector(size_t v_size, int* values) { //initialize a vector. Can only hold up to CHUNK (10)
        data_ptr = new int[CHUNK];
        capacity = CHUNK;
        n_elems = 0;
        bool include = false;
        
        for (int i=CHUNK-1; i>=0; i--) {
            if (i < v_size) {
                data_ptr[i] = values[i];
                n_elems++;
            } else {data_ptr[i] = 0;}
            
            // cout << i << " > ";
            // cout << data_ptr[i] << ", ";
        }
    };
    Vector(const Vector& v) {           // Copy constructor
        data_ptr = new int[v.capacity]; 
        capacity = v.capacity;
        n_elems = v.n_elems;
        
        for (int i=0; i<n_elems; i++) {
            data_ptr[i] = v.data_ptr[i];
        }
    };
    
    Vector& operator=(const Vector& v) {    // Copy assignment operator
        data_ptr = v.data_ptr;
        capacity = v.capacity;
        n_elems = v.n_elems;
        return *this;
    };  
    
    ~Vector() {
        delete data_ptr;
        data_ptr = nullptr;
    };

    int j; //used for type checking
    // Accessors
    int front() const {     // Return the int in position 0, if any
        assert(typeid(data_ptr[0]) == typeid(j));
        return data_ptr[0];
    };
    
    int back() const {   // Return last element (position n_elems-1)
        assert(typeid(data_ptr[n_elems-1]) == typeid(j));
        return data_ptr[n_elems-1];
    };
    
    int at(size_t pos) const {   // Return element in position "pos" (0-based)
        assert((pos >=0) && (pos < n_elems));
        assert(typeid(data_ptr[pos]) == typeid(j));
        return data_ptr[pos];
    };
    
    size_t size() const {       // Return n_elems
        return n_elems;
    };

    bool empty() const  {       // Return n_elems == 0
        return (n_elems == 0);
    };
    
    void see_values() {
        // cout << n_elems << endl;
        for (int i=0; i<n_elems; i++) {
            cout << data_ptr[i] << ' ';
        }
        cout << endl;
    };


    // Mutators
    int& operator[](size_t pos){    // Same as at but no bounds checking
        return data_ptr[pos];
    }
    
    void push_back(int item) {       // Append a new element at the end
        if (n_elems >= capacity) {grow();}
        n_elems += 1;
        data_ptr[n_elems-1] = item;
    };
    
    void pop_back() {        // --n_elems (nothing else to do)
        --n_elems;
    };
    
    void erase(size_t pos) {    // Remove item in position pos by shuffling left
        assert((pos >=0) && (pos < n_elems));
        for (int i=0; i<n_elems-1; i++) { 
            if (i >= pos) {
                data_ptr[i] = data_ptr[i+1];
            }
        }
        --n_elems;
    }
    
    void insert(size_t pos, int item) {     // Shuffle items right to make room for new element
        assert((pos >= 0) && (pos <= n_elems));
        if (n_elems >= capacity) {grow();}
        for (int i=n_elems; i>=0; i--) {
            if (i > pos) {
                data_ptr[i] = data_ptr[i-1]; }
            else if (i == pos) {
                data_ptr[i] = item;
            }
        }
        ++n_elems;
    };
    
    void clear() {      // n_elems = 0 (keep the current capacity)
        n_elems = 0; 
    };
    
    // Iterators
    int* begin() {   // Return a pointer to 1st element, or nullptr if n_elems == 0
        int* p = (n_elems == 0)? nullptr:data_ptr;
        return p;
    };
    
    int* end() {     // Return a pointer to 1 past last element, or nullptr if n_elems == 0
        int* p = (n_elems == 0)? nullptr: (data_ptr + n_elems - 1);
        return p;
    };

    // Comparators
    bool operator!=(const Vector& v) const {
        if (n_elems != v.n_elems) {return true;} 
        
        for (int i=0; i<n_elems; i++) {
            // cout << data_ptr[i] << ' ' << v.at(i) << endl;
            if (data_ptr[i] != v.at(i)) {return true;}
        }
        return false;
    }
    
    bool operator==(const Vector& v) const{
        if (n_elems != v.n_elems) {return false;} 
        
        for (int i=0; i<n_elems; i++) {
            if (data_ptr[i] != v.at(i)) {return false;}
        }
        return true;
    }; 
};
// #endif



int main() {
    int valsOne[5] = {5, 4, 3, 2, 1};   
    int valsTwo[10] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int valsThree[5] = {0, 0, 0, 0, 0};
    int a;
    int b;
    int c;
    int d;
    bool e;
    /*
Output:
    */
    
    Vector vecOne = Vector(5, valsOne); // testing initial constructor
    Vector vecTwo = Vector(10, valsTwo);
    Vector vecThree = Vector(5, valsThree);
    Vector vecFive = Vector();
    // Vector vecFive = Vector(4, {3, 4, 5, 6}); //this don't work
    vecFive.see_values();
    vecOne.see_values();
    /*
Output:
    
5 4 3 2 1 
    */
    
    Vector vecFour = vecOne; // testing copy constructors
    vecFour.see_values();
    vecFour = vecTwo;
    vecFour.see_values(); 
    /*
Output:
5 4 3 2 1 
6 7 8 9 10 11 12 13 14 15 
    */
    
    a = vecOne.front();     //testing accessors
    b = vecOne.back();
    c = vecOne.at(2);
    d = vecOne.size();
    e = vecOne.empty();
    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << endl;
    /*
Output:
5 1 3 5 0(false)
    */
    
    a = vecFive.front();     //testing accessors on the empty vector
    b = vecFive.back();
    // c = vecFive.at(2); //no values so this errors out like it should
    d = vecFive.size();
    e = vecFive.empty();
    cout << a << ' ' << b << ' ' << d << ' ' << e << ' ' << endl;
    /*
Output:
0 0 0 1(true)
    */
    
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

//saving progress
// #ifndef VECTOR_H
// #define VECTOR_H
 
#include <cstddef>
#include <iostream>
#include <cassert>
using std::size_t;
using std::cout;
using std::endl;

class Vector {
    enum {CHUNK = 10};
    int* data_ptr;
    // Pointer to the heap array
    size_t capacity;
    // Size of the current array allocation (total number of ints)
    size_t n_elems;
    // Number of int spaces currently in use, starting from pos 0
    void grow() {
        capacity += CHUNK;
        int* new_data_ptr = new int[capacity];
        
        for (int i=0; i<capacity; i++) {
            if (i>=n_elems) {new_data_ptr[i] = 0;}
            else {new_data_ptr[i] = data_ptr[i];}
            
        }
        
        cout << "grow" << endl;
        data_ptr = new_data_ptr;
        
        // delete new_data_ptr;
        // new_data_ptr = nullptr;
    };
public:
    // Object Mgt.
    Vector() {              //default
        data_ptr = new int[CHUNK];
        capacity = CHUNK;
        n_elems = 0;
    }; 
    
    Vector(size_t v_size, int* values) { //initialize a vector. Can only hold up to CHUNK (10)
        data_ptr = new int[CHUNK];
        capacity = CHUNK;
        n_elems = 0;
        bool include = false;
        
        for (int i=CHUNK-1; i>=0; i--) {
            if (i < v_size) {
                data_ptr[i] = values[i];
                n_elems++;
            } else {data_ptr[i] = 0;}
            
            // cout << i << " > ";
            // cout << data_ptr[i] << ", ";
        }
    };
    Vector(const Vector& v) {           // Copy constructor
        data_ptr = new int[v.capacity]; 
        capacity = v.capacity;
        n_elems = v.n_elems;
        
        for (int i=0; i<n_elems; i++) {
            data_ptr[i] = v.data_ptr[i];
        }
    };
    
    Vector& operator=(const Vector& v) {    // Copy assignment operator
        data_ptr = v.data_ptr;
        capacity = v.capacity;
        n_elems = v.n_elems;
        return *this;
    };  
    
    ~Vector() {
        delete data_ptr;
        data_ptr = nullptr;
    };

    int j; //used for type checking
    // Accessors
    int front() const {     // Return the int in position 0, if any
        assert(typeid(data_ptr[0]) == typeid(j));
        return data_ptr[0];
    };
    
    int back() const {   // Return last element (position n_elems-1)
        assert(typeid(data_ptr[n_elems-1]) == typeid(j));
        return data_ptr[n_elems-1];
    };
    
    int at(size_t pos) const {   // Return element in position "pos" (0-based)
        assert((pos >=0) && (pos < n_elems));
        assert(typeid(data_ptr[pos]) == typeid(j));
        return data_ptr[pos];
    };
    
    size_t size() const {       // Return n_elems
        return n_elems;
    };

    bool empty() const  {       // Return n_elems == 0
        return (n_elems == 0);
    };
    
    void see_values() {
        // cout << n_elems << endl;
        for (int i=0; i<n_elems; i++) {
            cout << data_ptr[i] << ' ';
        }
        // cout << endl;
    };


    // Mutators
    int& operator[](size_t pos){    // Same as at but no bounds checking
        return data_ptr[pos];
    }
    
    void push_back(int item) {       // Append a new element at the end
        if (n_elems >= capacity) {grow();}
        n_elems += 1;
        data_ptr[n_elems-1] = item;
    };
    
    void pop_back() {        // --n_elems (nothing else to do)
        --n_elems;
    };
    
    void erase(size_t pos) {    // Remove item in position pos by shuffling left
        assert((pos >=0) && (pos < n_elems));
        for (int i=0; i<n_elems-1; i++) { 
            if (i >= pos) {
                data_ptr[i] = data_ptr[i+1];
            }
        }
        --n_elems;
    }
    
    void insert(size_t pos, int item) {     // Shuffle items right to make room for new element
        assert((pos >= 0) && (pos <= n_elems));
        if (n_elems >= capacity) {grow();}
        for (int i=n_elems; i>=0; i--) {
            if (i > pos) {
                data_ptr[i] = data_ptr[i-1]; }
            else if (i == pos) {
                data_ptr[i] = item;
            }
        }
        ++n_elems;
    };
    
    void clear() {      // n_elems = 0 (keep the current capacity)
        n_elems = 0; 
    };
    
    // Iterators
    int* begin() {   // Return a pointer to 1st element, or nullptr if n_elems == 0
        int* p = (n_elems == 0)? nullptr:data_ptr;
        return p;
    };
    
    int* end() {     // Return a pointer to 1 past last element, or nullptr if n_elems == 0
        int* p = (n_elems == 0)? nullptr: (data_ptr + n_elems - 1);
        return p;
    };

    // Comparators
    bool operator!=(const Vector& v) const {
        if (n_elems != v.n_elems) {return true;} 
        
        for (int i=0; i<n_elems; i++) {
            // cout << data_ptr[i] << ' ' << v.at(i) << endl;
            if (data_ptr[i] != v.at(i)) {return true;}
        }
        return false;
    }
    
    bool operator==(const Vector& v) const{
        if (n_elems != v.n_elems) {return false;} 
        
        for (int i=0; i<n_elems; i++) {
            if (data_ptr[i] != v.at(i)) {return false;}
        }
        return true;
    }; 
};
// #endif

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