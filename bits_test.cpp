
// #include <ostream>
#include <windows.h>
#include "bits.h"

using namespace std;

void seeBitValues(int places, Bits bits) {
    int j = 0;
    for (int i; i<=6; i++) {
        j = bits.at(i);
        assert((j == 0) || (j == 1));
        //cout << j << endl;
    }
}

int main() {
    Bits myBits;
    myBits = Bits(10);

    assert(myBits.size() == 64);


    seeBitValues(4, myBits);

    return 0;
}

