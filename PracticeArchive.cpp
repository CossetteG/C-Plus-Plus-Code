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


//ver4 I think. 16/20 points but idk what to do from here
#include <iostream>
#include <string>
using namespace std;

void PrintMenu() {
   cout << "MENU" << endl
   << "c - Number of non-whitespace characters" << endl
   << "w - Number of words" << endl
   << "f - Find text" << endl
   << "r - Replace all !'s" << endl
   << "s - Shorten spaces" << endl
   << "q - Quit" << endl << endl;

}

int GetNumOfNonWSCharacters(string input) {
   int count = 0;
   
   for (char c:input) {
      (isspace(c))? :(count += 1);
   }
   
   return count;
}

int GetNumOfWords(string input) {
   int count;
   string final;
   int isize = input.size();
   bool prev = false;
   
   count = (input.at(isize-1) == ' ')? 0:1;
   
   for (char c:input) {
      if (isspace(c) && (prev == false)) {
         count += 1;
         prev = true;
      }
      else if (!isspace(c)) {
         prev = false;
      }
   }
   
   return count;

}

int FindText(string tofind, string input, int count = 0) {
   int const length = tofind.size();
   
   if (input.find(tofind) != string::npos) {
      count +=1;
      input = input.replace(input.find(tofind), length, "");
      return FindText(tofind, input, count);
   } else {
      return count;
   }
   
   
}

string ReplaceExclamation(string input) {
   string edited;
   for (char c: input) {
      edited += (c == '!')? '.':c;
   }
   return edited;
}

string ShortenSpace(string input) {
   string edited;
   bool prev = false;
   for (char c: input) {
      if (c == ' ') {
         if (!prev) {
            edited += c;
            prev = true;
         }
      } else {
         edited += c;
         prev = false;
      }
   }
   return edited;
}

string ExecuteMenu(char choice, string innyPutty) {
   string editedText;
   string lookFor;
   string scount;   
   int counted;
   
   switch (choice) {
      case 'q':
         return "**quit**";
      case 'c':
         counted = GetNumOfNonWSCharacters(innyPutty);
         scount = std::to_string(counted);
         editedText = "Number of non-whitespace characters: " + scount;
         return editedText;
      case 'w':
         counted = GetNumOfWords(innyPutty);
         scount = std::to_string(counted);
         editedText = "Number of words: " + scount;
         return editedText;
      case 'f':
         cout << "Enter a word or phrase to be found:" << endl;
         cin.ignore(256, '\n');
         getline(cin, lookFor);
         counted = FindText(lookFor, innyPutty);
         scount = std::to_string(counted);
         editedText = '"' + lookFor + "\" instances: " + scount;
         return editedText;
      case 'r':
         editedText = ReplaceExclamation(innyPutty);
         lookFor = "Edited text: ";
         return lookFor + editedText;
      case 's':
         editedText = ShortenSpace(innyPutty);
         lookFor = "Edited text: ";
         return lookFor + editedText;
      default :
         cout << "Again, ";
         return editedText;
      
   }
}

int main() {
   string userInput;
   char userSelect;
   string edited;
   bool quit;
   
   cout << "Enter a sample text:" << endl << endl;
   getline(cin, userInput);
   cout << "You entered: " << userInput << endl << endl;

   do{
      PrintMenu();
      cout << "Choose an option:" << endl;
      cin >> userSelect;
      edited = ExecuteMenu(userSelect, userInput);
      quit = (edited == "**quit**")? true:false;
      if (quit) {break;}
      cout << edited << endl << endl;
   }while(!quit);
   
   return 0;
}

//ver2
#include <iostream>
#include <vector>
using namespace std;

int Validate(char mode, int input) {
   if (mode == 'j') {
      if (input >= 0 && input <= 99) {return input;}
      else {cout << "Invalid jersey number " << input; return -1;}
   }
   else if (mode == 'r') {
      if (input >= 1 && input <= 9) {return input;}
      else {cout << "Invalid roster number " << input; return -1;}
   }
   else {cout << "choose a mode bruh"; return -1;}
}

void PrintRoster(vector<int> jerseys, vector<int> ratings, int len=-1) {
   if (len == -1) {len = jerseys.size();}
   
   cout << "ROSTER" << endl;
   
   for (int i=0; i<len; ++i) {
      cout << "Player " << (i + 1) << " -- Jersey number: " << jerseys.at(i) << ", Rating: " 
      << ratings.at(i) << endl;
   }
   cout << endl;
}

void PrintMenu() {
   cout << "MENU" << endl
   << "a - Add player" << endl
   << "d - Remove player" << endl
   << "u - Update player rating" << endl
   << "r - Output players above a rating" << endl
   << "o - Output roster" << endl
   << "q - Quit" << endl << endl
   << "Choose an option:" << endl;
}

void AddPlayer(vector<int> &jerseys, vector<int> &ratings) {
   int newJersey;
   int newRating;
   
   cout << "Enter a new player's jersey number:" << endl;
   cin >> newJersey;
   cout << "Enter the player's rating:" << endl;
   cin >> newRating;
   cout << endl;
   
   jerseys.push_back(newJersey);
   ratings.push_back(newRating);
}

void DeletePlayer(vector<int> &jerseys, vector<int> &ratings) {
   int jtoDelete;
   bool deleted = false;
   int len = jerseys.size();
   vector<int> newJ;
   vector<int> newR;
   
   cout << "Enter a jersey number: " << endl; 
   cin >> jtoDelete; 
   
   for (int i=0; i<len; ++i) {
      if (jerseys.at(i) == jtoDelete) {
         deleted = true;
      } else {
         newJ.push_back(jerseys.at(i));
         newR.push_back(ratings.at(i));
      }
   }
   
   jerseys = newJ;
   ratings = newR;
   
   if (!deleted) {cout << "No players removed."<<endl;}
}

void UpdateRating(vector<int> &jerseys, vector<int> &ratings) {
   int jtoUpdate;
   int rtoUpdate;
   int len = jerseys.size();
   
   cout << "Enter a jersey number:" << endl; 
   cin >> jtoUpdate;
   cout << "Enter a new rating for player:" << endl;
   cin >> rtoUpdate;
   cout << endl;
   
   for (int i=0; i<len; ++i) {
      if (jerseys.at(i) == jtoUpdate) {
         ratings.at(i) = rtoUpdate;
      }
   }
}

void OutputAboveRating(vector<int> jerseys, vector<int> ratings) {
   int minRating;
   int len = jerseys.size();
   
   cout << "Enter a rating:" << endl;
   cin >> minRating;
   cout << endl << endl; 
   
   cout << "ABOVE " << minRating << endl;
   for (int i=0; i<len; ++i) {
      if (ratings.at(i) > minRating) {
         cout << "Player " << (i + 1) << " -- Jersey number: " << jerseys.at(i) << ", Rating: " 
      << ratings.at(i) << endl;
      }
   }
   
   cout << endl;
}

void ExecuteMenu(char select, vector<int> &jerseys, vector<int> &ratings) {
   switch (select) {
      case ('a'): 
         AddPlayer(jerseys, ratings);
         //PrintRoster(jerseys, ratings);
         break;
      case ('d'):
         DeletePlayer(jerseys, ratings);
         PrintRoster(jerseys, ratings);
         break;
      case ('u'):
         UpdateRating(jerseys, ratings);
         PrintRoster(jerseys, ratings);
         break;
      case ('r'):
         OutputAboveRating(jerseys, ratings);
         break;
      case ('o'):
         PrintRoster(jerseys, ratings);
         break;
      case ('q'):
         break;
   }
}

int main() {
   int const initLen = 5;
   vector<int> playerJerseys(initLen); 
   vector<int> playerRatings(initLen);
   char select;
   
   for (int i=0; i<initLen; ++i) {
      cout << "Enter player " << (i + 1) << "'s jersey number:" << endl;
      cin >> playerJerseys.at(i); 
      
      cout << "Enter player " << (i + 1) << "'s rating:" << endl;
      cin >> playerRatings.at(i); 
      cout << endl;
   }

   PrintRoster(playerJerseys, playerRatings, initLen);
   
   do {
      PrintMenu();
      cin >> select;
      ExecuteMenu(select, playerJerseys, playerRatings); }
   while (select != 'q');
   //PrintRoster(playerJerseys, playerRatings);

   
   return 0;
}