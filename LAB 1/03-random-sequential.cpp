/* 
  generate an array A[] of length 1000 by generating each elements by using random integer generator in range [0,1000]. Again generate
  a random integer "n" and use sequentialSearch method to locate "n" in A[]. Calculate number of steps to find "n".

  * Repeat the process enclosed in {} 20 times for different "n"
      -> What is the minimum time taken?
      -> What is the maximum time taken?
      -> What is the average time taken?
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <climits>
using namespace std;

int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // found key at index i
        }
    }
    return -1; // key not found
}

int main() {
    const int N = 1000;
    int A[N];
    int n, key;
    int maxTime = 0, minTime = INT_MAX, totalTime = 0;
    srand(time(NULL)); // seed the random number generator
    
    // generate array A[] with random integers
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 1000 + 1; // random integer in [1, 1000]
    }
    
    // print the array A[]
    cout << "Array A[]: ";
    for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
    }
    cout << endl;
    
    // perform sequential search 20 times with different keys
    for (int i = 0; i < 20; i++) {
        key = rand() % 1000 + 1; // random integer in [1, 1000]
        auto start = chrono::high_resolution_clock::now();
        int index = sequentialSearch(A, N, key);
        auto end = chrono::high_resolution_clock::now();
        int timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count();
        if (index != -1) {
            cout << "Found " << key << " at index " << index << endl;
            cout << "Time taken: " << timeTaken << " microseconds" << endl;
            if (timeTaken > maxTime) {
                maxTime = timeTaken;
            }
            if (timeTaken < minTime) {
                minTime = timeTaken;
            }
            totalTime += timeTaken;
        }
        else {
            cout << "Could not find " << key << endl;
            cout << "Time taken: " << timeTaken << " microseconds" << endl;
            if (timeTaken > maxTime) {
                maxTime = timeTaken;
            }
            if (timeTaken < minTime) {
                minTime = timeTaken;
            }
            totalTime += timeTaken;
        }
    }
    
    // print results
    cout << "Maximum time taken: " << maxTime << " microseconds" << endl;
    cout << "Minimum time taken: " << minTime << " microseconds" << endl;
    cout << "Average time taken: " << totalTime / 20 << " microseconds" << endl;
    
    return 0;
}

