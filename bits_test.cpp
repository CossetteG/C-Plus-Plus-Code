
// #include <iostream>
#include <windows.h>
#include "bits.h"

using namespace std;

void seeBitValues(int places, Bits bits) {
    int j = 0;

    for (int i=0; i<places; i++) {
        j = bits.at(i);
        assert((j == 0) || (j == 1));
        // cout << j << ' ' << endl;
    }
}

int main() {
    Bits myBits;
    myBits = Bits(10);

    assert(myBits.size() == 64);

    myBits.set(2);      //pos count starts at 0 ---- bits = 14
    seeBitValues(4, myBits);

    myBits.reset(1);    // bits = 12
    seeBitValues(4, myBits);

    myBits.set();       // bits = 18somethingorothernumber
    seeBitValues(4, myBits);

    myBits.reset();     // bits = 0
    seeBitValues(4, myBits);

    myBits.assign(14);  // bits = 14
    seeBitValues(10, myBits);

    myBits.assign(0, true); //bits = 15
    seeBitValues(10, myBits);

    myBits.assign(2, false); //bits = 11
    seeBitValues(10, myBits);

    myBits.assign(2);
    seeBitValues(5, myBits);

    myBits.shift(1);   // bits = 4
    seeBitValues(5, myBits);

    myBits.shift(-2); // bits = 1
    seeBitValues(5, myBits);

    myBits.rotate(-2); //bits = 46whatever
    seeBitValues(5, myBits);

    myBits.rotate(3); //bits = 2
    seeBitValues(5, myBits);

    myBits.assign(10);
    myBits.toggle(1);   //bits = 8
    seeBitValues(5, myBits); 

    return 0;
}

