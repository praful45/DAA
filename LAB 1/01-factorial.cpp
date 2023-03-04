/*
  Implement the factorial funtion in recursive and non recursive approach 
  conduct time analysis by using time() avaialbe in time.h
  In both approaches show the space and time complexity
*/

#include <iostream>
#include <chrono>
using namespace std;

unsigned long long  fact_rec(int n) {
  if (n<=0)   return 1;
  return n*fact_rec(n-1);
}

unsigned long long  fact_iterative(int n) {
    unsigned long long   result=1;
    for(int i=3; i<=n; i++) {
      result*=i;
    }
    return result;
}


int main() {
    int n; 
    cout<<"Enter the number: ";
    cin >> n;
    cout << endl;
    for(int i=0; i<n; i=i+10000 ) {

        // Using time point and system_clock
        chrono::time_point<chrono::system_clock> start_rec, end_rec;
      
        cout<< "-------[time for factorial(" <<i<<")= " << (unsigned long long) fact_rec(i) << "]-------"<<endl; 

        start_rec = chrono::system_clock::now();
        fact_rec(i); 
        end_rec = chrono::system_clock::now();
      
        chrono::time_point<chrono::system_clock> start_iter, end_iter;
        start_iter = chrono::system_clock::now();
        fact_iterative(i); 
        end_iter = chrono::system_clock::now();

        chrono::duration<double,std::nano> elapsed_seconds_rec = end_rec - start_rec;
        chrono::duration<double,std::nano> elapsed_seconds_iter = end_iter - start_iter;
        cout << "elapsed time for recursive (in ten thousands nanoseconds): " << elapsed_seconds_rec.count()/10000 << endl;
        cout << "elapsed time for iterative (in ten thousands nanoseconds): " << elapsed_seconds_iter.count()/10000 << endl;
        cout<< "----------------------------------------\n\n"<<endl; 
    }
}
