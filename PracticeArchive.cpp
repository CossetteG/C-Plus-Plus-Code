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

#include <iostream>
using namespace std;

int main() {

   // Draw tree
   cout << "   *"    << endl;
   cout << "  ***"   << endl;
   cout << " *****"  << endl;
   cout << "*******" << endl;
   cout << "  ***"   << endl;
   cout << endl << endl;

   cout << "/\\" << "   /\\" << endl;
   cout << "  o o" << endl;
   cout << " =   =" << endl;
   cout << "  ---" << endl;
   
   /* Type your code here. */

   return 0;
}

#include <iostream>
#include <iomanip>              // needed for setprecision() and fixed
#include <cmath>                // needed for ceil()
using namespace std;

int main() {
   double width;
   double height;
   double wallArea;
   
   const double paintCovers = 350;
   double paintNeeded;
   int cansNeeded;
   
   double pricePerCan;
   double paintCost;
   const double taxRate = .07;
   double taxAmount;
   double totalCost;
   
   cin >> width;
   cin >> height;
   wallArea = width * height;
   cout << fixed << setprecision(1) << "Wall area: " << wallArea << " sq ft" << endl;
   
   paintNeeded = wallArea / paintCovers; 
   cansNeeded = ceil(paintNeeded);
   cout << fixed << setprecision(3) << "Paint needed: " << paintNeeded << " gallons" << endl;
   cout << "Cans needed: " << cansNeeded << " can(s)" << endl;
   
   cin >> pricePerCan;
   paintCost = cansNeeded * pricePerCan;
   taxAmount = paintCost * taxRate;
   totalCost = paintCost + taxAmount;
   
   cout << fixed << setprecision(2) << "Paint cost: $" << paintCost << endl;
   cout << fixed << setprecision(2) << "Sales tax: $" << taxAmount << endl;
   cout << fixed << setprecision(2) << "Total cost: $" << totalCost << endl;
   /* Type your code here. */

   return 0;
}

using namespace std;

int main() {
   string inString;
   bool isValid;
   
   getline(cin, inString);
   isValid = false;
   
   for (int i=0; i<inString.size(); i++) {
      if (!!(isspace(inString.at(i)))) {
         isValid = true;
      }
   }

   if (isValid) {
      cout << "Valid string" << endl;
   }
   else {
      cout << "Invalid string" << endl;
   }

   return 0;
}