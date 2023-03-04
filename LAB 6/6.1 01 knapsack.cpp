//6.1 0-1 knapsack problem using DP
#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int K[n+1][W+1];
 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
 
    return K[n][W];
}

int main() {
    
    int n = 10;
    int W = 1000;
    int wt[n], val[n];
    srand(time(0));
    for(int i=0; i<n; i++){
        wt[i] = rand() % W + 1;
        val[i] = rand() % 100 + 1;
    }

    clock_t start_time, end_time;
    start_time = clock();

    int res = knapsack(W, wt, val, n);

    end_time = clock();

    double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
    cout<<"Result = "<<res<<endl;
    cout << "Time taken by the function is : " << fixed << time_taken*1000*1000 << setprecision(5);
    cout << " microsec " << endl;

    return 0;
}

