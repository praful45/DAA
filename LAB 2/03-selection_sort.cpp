#include<iostream>
#include<chrono>
#include<cmath>
using namespace std;

void selectionSort(int arr[], int n) {
  int i, j, position, temp;
  for(i=0;i<n-1;i++) {
      position=i;
      for(j=i+1;j<n;j++) {
          if(arr[position]>arr[j]) {
              position=j;
          }
      }
      if(position!=0) {
          temp=arr[i];
          arr[i]=arr[position];
          arr[position]=temp;
      }
  }
}


int main() {

    /* for generating random numbers  */
    int n;
    cout << "\n\tno. of elements \ttime elapsed\n";
    cout << "--------------------------------------------------\n";
    for(int i=1;i<17;++i) {
        n = pow(2,i);
        int *data = new int[n];

        srand(time(0));
        for (int i = 0; i < n; i++)
          data[i]= (rand() % (0 - 100000+ 1)) + 0;

        chrono::time_point<chrono::system_clock> start_unsorted, end_unsorted;
        start_unsorted = chrono::system_clock::now();
        selectionSort(data, n);
        end_unsorted = chrono::system_clock::now();
        
        
        chrono::duration<double,std::milli> elapsed_sec_unsorted = end_unsorted - start_unsorted;

        cout << "\t" << n << "\t\t\t" << elapsed_sec_unsorted.count() << "ms" << endl; 

        delete [] data;
    }
}
