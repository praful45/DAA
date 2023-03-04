#include<iostream>
#include<cmath>
#include<chrono>
using namespace std;


int* minMaxIter(int *arr, int size) {

  int *MinMax = new int[2];
  MinMax[0]=arr[0];         // for minimum number
  MinMax[1]=arr[1];         // for maximum number
  for(int i=0; i<size; ++i) {
    if(arr[i] < MinMax[0])
      MinMax[0]= arr[i];
    if(arr[i] > MinMax[1])
      MinMax[1]= arr[i];
  }
  return MinMax;
}


void minMaxDAC(int *arr,int start, int end, int &min,int &max) {

  int min1,max1;
  if(start == end) {
    min = max = arr[start];
  }else if( start == end-1) {
      if(arr[start] < arr[end]) {
          min = arr[start];
          max = arr[end];
      }else {
          min = arr[end];
          max = arr[start];
      }
  }else {
      int mid = (start + end) / 2;
      minMaxDAC(arr,start,mid,min,max);
      max1 = max; min1 = min;
      minMaxDAC(arr,mid+1,end,min,max);
      if(max <max1)
          max = max1;
       if(min > min1)
          min = min1;
  }
}

int main() {
    /* for generating random numbers  */
    int n;

    cout << "\t\t\t| ellapsed time in milliseconds for ";
    cout << "\n   number of elements   |   iterative \t\t recursive " << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    for(int i=1;i<19;++i) {
        n = pow(2,i);
        int *arr = new int[n];

        srand(time(0));
        for (int i = 0; i < n; i++)
          arr[i]= (rand() % (0 - 1000+ 1));

        chrono::time_point<chrono::system_clock> start_iter, end_iter;
        start_iter = chrono::system_clock::now();
        int *MinMax = minMaxIter(arr,n);
        end_iter = chrono::system_clock::now();
        chrono::duration<double,std::nano> elapsed_sec_iter = end_iter - start_iter;

        int min,max;   
        chrono::time_point<chrono::system_clock> start_rec, end_rec;
        start_rec = chrono::system_clock::now();
        minMaxDAC(arr,0,n-1,min,max);
        end_rec = chrono::system_clock::now();
        chrono::duration<double,std::nano> elapsed_sec_rec = end_rec - start_rec;


        cout<<"\t" << n << "\t\t\t" << elapsed_sec_iter.count() << "\t\t  " << elapsed_sec_rec.count() << "\t\t-> min = "<< min << "\tmax = " << max<< endl;
    }
}
