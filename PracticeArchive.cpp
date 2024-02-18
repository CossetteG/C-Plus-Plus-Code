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

#include <iostream>
using namespace std;

int main() {
   int highwayNumber;
   
   cin >> highwayNumber;

   if (highwayNumber < 1 || highwayNumber > 999 || highwayNumber % 100 == 0) {
      cout << highwayNumber << " is not a valid interstate highway number." << endl;
   }
   else {
      cout << "I-" << highwayNumber << " is ";
      
      if (highwayNumber > 100) {
         cout << "auxiliary, ";
         
         int serveNumber;
         serveNumber = highwayNumber % 100;
         cout << "serving I-" << serveNumber;
      }
      else {
         cout << "primary";
      }
      
      string direction;
      direction = (highwayNumber % 2 == 0)? "east/west.":"north/south.";
      cout << ", going " << direction << endl;
   }   

   return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
   string firstN;
   string middleN;
   string lastN;
   
   cin >> firstN;
   cin >> middleN;
   cin >> lastN; 
   
   if (lastN == "") {
      lastN = middleN;
      middleN = "";
   }
   
   /*
   cout << firstN << endl;
   cout << middleN << endl;
   cout << lastN << endl;
   */
   
   char firstInit;
   char middleInit;
   
   firstInit = firstN.at(0);
   
   cout << lastN << ", " << firstInit << ". ";
   
   if (middleN != "") {
      middleInit = middleN.at(0);
      cout << middleInit << '.';
   }
   
   cout << endl;

   return 0;
}

#include <bitset>
#include <iostream>
using namespace std;

int main() {
    cout << "Enter the integer that holds the bits: ";
    unsigned int n;
    cin >> n;

    cout << "Enter the rightmost bit position: ";
    unsigned int k;
    cin >> k;

    cout << "Enter the leftmost bit position: ";
    unsigned int m;
    cin >> m;
    
    unsigned int sol;
    sol = (n & (((1 << (m-k+1)) - 1) << k)) >> k;
    
    cout << "Extracting bits " << k << " through " << m << " from ";
    cout << n << " = " << bitset<32>(n) << ':' << endl;
    cout << "Result = " << sol << " = " << bitset<32>(sol) << endl;

}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string userin;
   string userinCOPY;
   int inputLength;
   int halfLength;
   bool isPalindrome;
   string outputstr;
   int i;
   
   isPalindrome = true;
   getline(cin, userin);
   inputLength = userin.size();
   userinCOPY = userin;
   
   while (userin.find(' ') != string::npos) {
      int itemIndex;
      itemIndex = userin.find(' ');
      userin.replace(itemIndex, 1, "");
   }
   
   inputLength = userin.size();
   halfLength = inputLength / 2;
   
   for (i=0; i < halfLength; ++i) {
      int endchar;
      endchar = inputLength - i -  1;
      //cout << userin.at(i) << ' ' << userin.at(endchar) << endl;
      
      if (userin.at(i) == userin.at(endchar)) {
         continue;
      }
      
      isPalindrome = false;
   }
   
   outputstr = (isPalindrome)? "palindrome: ":"not a palindrome: ";
   //cout << inputLength << ' ' << halfLength;
   cout << outputstr << userinCOPY << endl;

   return 0;
}

#include <iostream>
using namespace std;

int main() {
   int width;
   int height;
   int arrow;
   int i;
   int j;
   
   cin >> height;
   cin >> width;

   do {
      cin >> arrow;
   } while (arrow <= width);
   
   for (i=0; i < height; ++i) {
      for (j=0; j < width; ++j) {
         cout << '*';
      }
      cout << endl;
   }
   
   for (arrow; arrow >= 0; --arrow) {
      for (j=0; j<arrow; ++j) {
         cout << '*';
      }
      if (arrow > 0) {
      cout << endl;
      }
   }

   return 0;
}
