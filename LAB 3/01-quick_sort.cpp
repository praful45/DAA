#include<iostream>
#include<chrono>
#include<cmath>

using namespace std;


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArr(int *arr,int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << "  " ;
    }
    cout<<endl;
}




int Partition(int *A, int start, int end) {
    int pivot = A[start];
    int i = start - 1, j = end + 1;

    while(true) {
       /* 
            here pointer i moves RHS when A[i] < pivot
            if A[i] > pivot then pointer i will hold the current value of i 
       */
        do {
            i++;
        }while(A[i] < pivot);
       /* 
            here pointer j moves LHS when A[j] > pivot
            if A[j] < pivot then pointer j will hold the current value of j 
       */
        do {
            j--;
        }while(A[j] > pivot);
        if(i>=j){
            return j;
        }

        swap(&A[i],&A[j]);
    }

}

void QuickSort(int arr[], int start, int end) {
    if(start>=end)  return; 
    int pIndex = Partition(arr, start,end); 
    QuickSort(arr,start,pIndex);
    QuickSort(arr,pIndex+1, end);
}


int main() {
  
    cout << "\n\tno. of elements \t\ttime elapsed\t\n";
    cout << "------------------------------------------------------\n";

    for(int i=1;i<24;++i) {
        int n = pow(2,i);
        int *data = new int[n];

        srand(time(0));
        for (int i = 0; i < n; i++)
          data[i]= (rand() % (0 - 100000+ 1)) + 0;
        

        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        QuickSort(data, 0,n-1);
        end = chrono::system_clock::now();
        
        
        chrono::duration<double,std::milli> elapsed_sec = end - start;
        
        cout<< "\t" << n << "\t\t\t\t" << elapsed_sec.count()<<"ms" <<endl;

        delete [] data;
    }
}
