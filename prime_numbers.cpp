#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <mutex>
#include <thread>

using namespace std;

/* README
This code uses process of elimination to find prime numbers
(becuase I think it will be more efficient, and nothing will need to be rechecked once it has been checked)
The rubric says to print prime numbers as you find them, but I'm going to print them all at the end
to prevent false positives from printing. I will also report any false positives if found. 

Another thing to note about this code is that each object's index in the master list and the number it 
represents (.first) are the same, which works for this project because to find prime numbers you must 
always start at the beginning. 

EDIT -threads are tuples don't wanna be compatible for me today so the value of any index in master list
tells you whether the index number is prime
EDIT 2 ^that was not the actual problem but I did leave it as index anyway

The threads are split up based on its modulo of 4 (0, 1, 2, 3) 
*/

mutex mu;
const int MAX = 1000000;
// vector<pair<int, bool>*> masterlist; //number, is prime
vector<bool> masterlist;
vector<int> counts = {2,0,0,0,0};

void weed_out (int base, int threadnum) {
    int j = 2; //any multiple of an odd number is not prime
    if (base == 4 || threadnum == 2) {j = 1;} //even numbers greater than 2 are automatically not prime

    while ((base *j) <= MAX) {
        if (masterlist[base*j] == true) {
            mu.lock();
            masterlist[base*j] = false; //eliminating from prime numbers
            // cout << to_string(base*j) << endl;
            mu.unlock();
        }
        j++;
    }
}

void find_prime (int threadnum) {
    int k = 1;
    
    while (k <= MAX / 4) {
        int candidate = 4*k+threadnum; //every k is the next four numbers, so thread four would be multiples of four
        if (masterlist[candidate] == true && threadnum != 2) { //it's prime if it hasn't been eliminated yet lol
            counts[threadnum]++;
        }
        weed_out(candidate, threadnum);
        k++;
    }
}


int main() {
    cout << "start" << endl;
    for (int i=0; i<=MAX; i++) {
        // pair<int, bool> *p = new pair<int, bool>;
        // p->first = i;
        // p->second = true;
        // masterlist.push_back(p);
        masterlist.push_back(true);
    };

    masterlist[0] = false;
    masterlist[1] = false; 
    // k=0, would break my code, 2 and 3 are already set to true
    masterlist[9] = false; //I don't check multiples of 3 so 3x3 is missed

    thread thr_one(find_prime, 1);
    thread thr_thr(find_prime, 3);
    
    thread thr_two(find_prime, 2); 
    thread thr_four(weed_out, 4, 4);

    thr_one.join();
    thr_thr.join();
    thr_two.join();
    thr_four.join();

    // find_prime(1);
    // find_prime(3);
    // find_prime(2);
    // weed_out(4, 4);

    ofstream ofs("primes.dat");
    int final_count = 0;
    for (int i=0; i<MAX; i++) {
        if (masterlist[i]) {
            ofs << to_string(i) << endl; 
            final_count++;
        }
    }

    int counted_total = counts[1] + counts[2] + counts[3] + counts[4];
    ofs << "Summary:\n" 
        << "Prime numbers found: " << to_string(final_count) << endl
        << "There were " << to_string(counts[0]) << " prime numbers found outside of the threads" << endl
        << "Thread 1 found " << to_string(counts[1]) << " prime numbers" << endl
        << "Thread 2 found " << to_string(counts[2]) << " prime numbers" << endl
        << "Thread 3 found " << to_string(counts[3]) << " prime numbers" << endl
        << "Thread 4 found " << to_string(counts[4]) << " prime numbers" << endl
        << "There were " << to_string(counted_total) << " prime numbers found in the threads and "
        << to_string(counted_total - final_count) << " false positives" << endl;

    cout << "done";
}