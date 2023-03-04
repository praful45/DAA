//4.2 job sequencing
#include <iostream>
#include <algorithm>
#include<chrono>

using namespace std;
using namespace std::chrono;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int findMaxProfit(Job jobs[], int n) {
    sort(jobs, jobs + n, cmp);
    bool slots[n]={false};
    for (int i = 0; i < n; i++) {
    	for(int j = min(n,jobs[i].deadline)-1;j>=0;j--){
    		if(!slots[j]){
    			slots[j]=true;
    			break;
			}
		}
    }
    int maxProfit = 0;
    for(int i=0;i<n;i++){
    	if(slots[i]){
    		maxProfit = jobs[i].profit;
		}
	}
	return maxProfit;
}

int main() {
    Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    int n = sizeof(jobs)/sizeof(jobs[0]);
    auto start= high_resolution_clock::now();
    int maxProfit = findMaxProfit(jobs,n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout<<"Maximum Profit: "<<maxProfit<<endl;
    cout<<"Time taken: "<<duration.count()<<" microseconds"<<endl;
    return 0;
}

