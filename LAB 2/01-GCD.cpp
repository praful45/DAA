#include<iostream>
#include<chrono>
using namespace std;
typedef unsigned long long ull;
int rec_steps=0;
int iter_steps = 0;

ull GCD_rec(ull  a,ull  b) {
  if (b==0) {
    return a;
  }else if(a==0)
      return b;
  rec_steps++;
  return GCD_rec(b,a%b);
}

ull GCD_iter(ull  a,ull  b){
  ull  R;
  if(a ==0) return b;
  if( b==0) return a;
  while((a%b)>0) {
    iter_steps++;
    R = a % b;
    a = b;
    b = R;
  }
  return b;
}
int main() {
  ull a,b;
   ull gcd;
  
  cout << "Enter two numbers a and b: ";
  cin >> a >> b ;

  chrono::time_point<chrono::system_clock> start_rec, end_rec;
      
  cout<< "-------[time to calculate GCD("<<a<<"," << b << ") = "<< GCD_iter(a,b) <<"]-------"<<endl; 

  start_rec = chrono::system_clock::now();
  gcd = GCD_rec(a,b);
  end_rec = chrono::system_clock::now();

  chrono::time_point<chrono::system_clock> start_iter, end_iter;
  start_iter = chrono::system_clock::now();
  GCD_iter(a,b);
  end_iter = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds_rec = end_rec - start_rec;
  chrono::duration<double> elapsed_seconds_iter = end_iter - start_iter;
  cout << "\telapsed time for recursive : " << elapsed_seconds_rec.count() << "s\n";
  cout << "\tsteps in recursive approach : " << rec_steps << endl << endl;
  cout << "\telapsed time for iterative : " << elapsed_seconds_iter.count() << "s\n";
  cout << "\tsteps in iterative approach : " << iter_steps << endl;
  cout<< "-------------------------------------------------\n\n"<<endl; 
}
