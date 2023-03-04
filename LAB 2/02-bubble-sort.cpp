#include<iostream>
#include<chrono>
#include<cmath>
using namespace std;

void bubbleSort(int arr[], int n) {
  for(int i=0; i<n-1; ++i) {
    for(int j=0; j<n-i-1; ++j) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }  
}

void printArr(int *arr,int n) {
  for(int i=0; i<n; i++) {
    cout << arr[i] << "   " ;
  }
  cout << endl;
}
int main() {
 
    int n;
    
    cout << "\n\tno. of elements \ttime elapsed\n";
    cout << "--------------------------------------------------\n";
    for(int i=1;i<18;++i) {
        n = pow(2,i);
        int *data = new int[n];

        srand(time(0));
        for (int i = 0; i < n; i++)
          data[i]= (rand() % (0 - 100000+ 1)) + 0;
        
        chrono::time_point<chrono::system_clock> start_unsorted, end_unsorted;
        start_unsorted = chrono::system_clock::now();
        bubbleSort(data, n);
        end_unsorted = chrono::system_clock::now();
        
        chrono::duration<double,std::milli> elapsed_sec_unsorted = end_unsorted - start_unsorted;
        
        cout<< "\t" << n << "\t\t\t\t" << elapsed_sec_unsorted.count()<<"ms"<<endl;

        delete [] data;
    }

}
