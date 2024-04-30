// #ifndef VECTOR_H
// #define VECTOR_H
 
// #include <cstddef>
// #include <iostream>
// #include <cassert>
#ifndef VECTOR_H
#define VECTOR_H

 
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
        data_ptr = new int[v.capacity];
        capacity = v.capacity;
        n_elems = v.n_elems;
        
        for (int i=0; i<n_elems; i++) {
            data_ptr[i] = v.data_ptr[i];
        }
        return *this;
    };  
    
    ~Vector() {
        delete data_ptr;
        data_ptr = nullptr;
    };

    // int j; //used for type checking
    // Accessors
    int front() const {     // Return the int in position 0, if any
        // assert(typeid(data_ptr[0]) == typeid(j));
        return data_ptr[0];
    };
    
    int back() const {   // Return last element (position n_elems-1)
        // assert(typeid(data_ptr[n_elems-1]) == typeid(j));
        return data_ptr[n_elems-1];
    };
    
    int at(size_t pos) const {   // Return element in position "pos" (0-based)
        if ((pos <0) || (pos >= n_elems)) 
            {throw std::range_error("Out of rage (at func)");}
        // assert(typeid(data_ptr[pos]) == typeid(j));
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
        int j;
        for (int i=0; i<n_elems; i++) {
            j = data_ptr[i];
            // cout << data_ptr[i] << ' ';
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
        if ((pos <0) || (pos >= n_elems)) 
            {throw std::range_error("Out of rage (erase func)");}

        for (int i=0; i<n_elems-1; i++) { 
            if (i >= pos) {
                data_ptr[i] = data_ptr[i+1];
            }
        }
        --n_elems;
    }
    
    void insert(size_t pos, int item) {     // Shuffle items right to make room for new element
        if ((pos <0) || (pos >= n_elems)) 
            {throw std::range_error("Out of rage (insert func)");}
            
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

#endif