
#include <bitset>
#include <cassert>
#include <cmath>
// #include <iostream>
/*Student note: iostream was not working on my machine for some reason, 
so nothing using ostream or cout has been tested. <3 Cossette*/

class Bits {
    using IType = unsigned long long; // We only have to change the integer type here, if desired
    enum {NBITS = sizeof(IType)*8};
    IType bits = 0;
public:
    Bits() = default;
    Bits(IType n) {
        bits = n;
    }
    
    static int size() {
        return NBITS;
    }
    bool at(int pos) const {  // Returns (tests) the bit at bit-position pos
        assert(0 <= pos && pos < NBITS);
        return bits & (IType(1) << pos);
    }
    void set(int pos) {                   // Sets the bit at position pos
        assert(0 <= pos && pos < NBITS);
        // if (this->at(pos) == 0) {
        //     IType add = (pow(2, (pos)));
        //     this->bits += add; };

        this->bits = (this->bits | IType(1) << pos);
    };       
    void set() {                           // Sets all bits
        IType total = 0;
        for (int i=0; i<NBITS; i++) {
            IType add = (pow(2, (i)));
            total += add;
        }
        assert(total != 0);
        this->bits = total;
    };               
    void reset(int pos){            // Resets (makes zero) the bit at position pos
        assert(0 <= pos && pos < NBITS);
        if (this->at(pos) == 1) {
        //     IType subtr = (pow(2, (pos)));
        //     this->bits -= subtr; } ;
            IType r = pow(2, (pos));
            this->bits = this->bits ^ r;
        }
    };      
    void reset() {                  // Resets all bits
        this->bits = 0;
    };             
    void assign(int pos, bool val) {    // Sets or resets the bit at position pos depending on val
        assert(0 <= pos && pos < NBITS);
        if (val == true) {
            this->set(pos);
        }else {
            this->reset(pos);
        }
    }; 
    void assign(IType n) {      // Replaces the underlying integer with n
        this->bits = n;
    };     
    void toggle(int pos){       // Flips the bit at position pos
        assert(0 <= pos && pos < NBITS);
        if (this->at(pos) == 1) {this->reset(pos);}
        else{this->set(pos);}
        
    };     
    void toggle() { // Flips all bits
        this->bits = ~(this->bits);
    };            
    void shift(int n) {     // If n > 0, shifts bits right n places; if n < 0, shifts left
        int m = -1*n;
        if (n > 0) {
            this->bits = this->bits<<n;
        } else {
            this->bits = this->bits>>m;
        }
    }; 
    void rotate(int n) {   // If n > 0, rotates right n places; if n < 0, rotates left
        n = n % NBITS;
        int m = -1*n;
        IType r = 0;

        if (n > 0) {
            for (int i=0; i<n; i++) {
                if (this->at(NBITS - i-1) == 1) { 
                r += pow(2, (NBITS - i-1));} }
            r = r >> (NBITS - n);
            this->shift(n);
            this->bits = this->bits | r;
        } else if (n < 0) {
            for (int i=0; i<m; i++) {
                if (this->at(i) == 1) { 
                r += pow(2, (i));}}
            r = r << (NBITS - m);
            this->shift(n);
            this->bits = this->bits | r;
        } else {}
    }; 
    int ones() const{        // Returns how many bits are set in the underlying integer
        int total = 0;
        for (int i=0; i>NBITS; i++) {
            if (this->at(i) == 1) { total += 1;}
        }
        return total;
    }
    int zeroes() const {      // Returns how many bits are reset in the underlying integer
        return NBITS - ones();
    }
    IType to_int() const {
        return bits;
    }
    friend bool operator==(const Bits& b1, const Bits& b2) {
        return b1.bits == b2.bits;
    }
    friend bool operator!=(const Bits& b1, const Bits& b2) {
        return b1.bits != b2.bits;
    }
    // friend std::ostream& operator<<(std::ostream& os, const Bits& b) {
    //     return os << std::bitset<NBITS>(b.bits);    // Be sure to #include <bitset>
    // }
};
  

