// C++ program to illustrate time point
// and system clock functions
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;


// the function returns the nth element in fibonacci series 
unsigned long long fibo_rec(unsigned n) {
    if (n < 2) return 1;
    return fibo_rec(n-1) + fibo_rec(n-2);
}

unsigned long long fibo_iterative(unsigned n) {
    if (n < 2) return 1;
    unsigned long long first,second,third;
    first = 1;
    second = 1;
    for(unsigned int i=2; i<n; i++) {
        third = first + second;
        first = second;
        second = third;    
    }
    return third;
}
  
 
int main() {
    
    int n; 
    cout<<"Enter the number: ";
    cin >> n;
    cout<<endl;


    for(int i=0; i<n; i=i+4 ) {

        // Using time point and system_clock
        chrono::time_point<chrono::system_clock> start_rec, end_rec;

        cout<< "-------[time to generate fibonacci series for fibonacci("<<i+1<<")]-------"<<endl; 
        start_rec = chrono::system_clock::now();
        for(int j=0; j<i+1; j++) {
             cout << fibo_rec(j)<< "  ";
        }
        end_rec = chrono::system_clock::now();
        cout << endl;
      
        chrono::time_point<chrono::system_clock> start_iter, end_iter;
        start_iter = chrono::system_clock::now();
        for(int j=0; j<i+1; j++) {
             fibo_iterative(j);
        }
        end_iter = chrono::system_clock::now();
        cout << endl;

        chrono::duration<double,std::micro> elapsed_seconds_rec = end_rec - start_rec;
        chrono::duration<double,std::micro> elapsed_seconds_iter = end_iter - start_iter;
        cout << "elapsed time for recursive (in thousands microseconds): " << elapsed_seconds_rec.count()/1000 << endl;
        cout << "elapsed time for iterative (in thousands microseconds): " << elapsed_seconds_iter.count()/1000 << endl;
        cout<< "----------------------------------------\n\n"<<endl; 
    }
}

