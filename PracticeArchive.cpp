/*while this file is a c++ file, it is not meant to be run
it is an archive of the c++ code that I write myself*/

#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    int i;
    cout << "Hello World boogie oogie" << endl;

    return 0;
}


#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;

int main() {
   float initialFreq;
   float oneKeyUp;
   float twoKeyUp;
   float threeKeyUp;
   const float r = pow(2.0, (1.0/12.0));
   
   cin >> initialFreq;
   
   oneKeyUp = initialFreq * pow(r, 1);
   twoKeyUp = initialFreq * pow(r, 2);
   threeKeyUp = initialFreq * pow(r, 3);
   
   cout << fixed << setprecision(2) << initialFreq << " Hz" << endl;
   cout << fixed << setprecision(2) << oneKeyUp << " Hz" << endl;
   cout << fixed << setprecision(2) << twoKeyUp << " Hz" << endl;
   cout << fixed << setprecision(2) << threeKeyUp << " Hz" << endl;

   /* Type your code here. Include the math library above first. */

   return 0;
}
