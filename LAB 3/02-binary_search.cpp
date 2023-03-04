#include <iostream>
#include<chrono>
#include<cmath>

using namespace std;

void printArr(int *arr,int n) {
    for(int i=0; i<n; i++) {
      cout << arr[i] << "   " ;
    }
    cout << endl;
}

int binarySearch(int array[], int x, int low, int high) {
  
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}


int binarySearchDAC(int arr[], int x, int low, int high) {
    if(low <= high) {
        int mid = low + (high -low) /2;

        if(arr[mid]==x) {
            return mid+1;
        }
        else if(x < arr[mid]) {
            return binarySearchDAC(arr,x,low, mid-1);
        }
        else {
            return binarySearchDAC(arr,x,mid+1,high);
        }
    }
    return 0;
}



int main(void) {

    cout << "\nSearching the left most element for worst case\n";
    cout << "\n    no. of elements \t\tIterative \t\t\tRecursive"<<endl;
    cout<< "------------------------------------------------------------------------------------------" << endl;
    for(int i=1;i<24;++i) {
        int n = pow(2,i);
        int *data = new int[n];

        srand(time(0));
        for (int i = 0; i < n; i++)
          data[i]= (rand() % (0 - 100000+ 1)) + 0;

        int x=data[0];


        chrono::time_point<chrono::system_clock> start_ite, end_ite;
        start_ite = chrono::system_clock::now();
        int result_ite = binarySearch(data,x,0,n-1);
        end_ite = chrono::system_clock::now();
        chrono::duration<double,std::milli> elapsed_ite = end_ite - start_ite;

        chrono::time_point<chrono::system_clock> start_DAC, end_DAC;
        start_DAC = chrono::system_clock::now();
        int result_DAC = binarySearchDAC(data, x, 0, n - 1);
        end_DAC = chrono::system_clock::now();
        chrono::duration<double,std::milli> elapsed_DAC = end_DAC - start_DAC;

        cout<< "\t" << n << "\t\t\t\t" << elapsed_ite.count()<<"ms" << "\t\t\t" << elapsed_DAC.count()<<"ms" <<endl;

        delete [] data;
    }
}
