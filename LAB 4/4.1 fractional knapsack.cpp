//fractional knapsack problem
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractional_knapsack(int capacity, Item items[], int n) {
    sort(items, items + n, cmp);
    int current_weight = 0;
    double current_value = 0;
    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            current_value += items[i].value;
        } else {
            int remaining_weight = capacity - current_weight;
            current_value += (double) remaining_weight * items[i].value / items[i].weight;
            break;
        }
    }
    return current_value;
}

int main() {
    int capacity = 50;
    int n = 5;
    Item items[n] = {
        { 60, 10 }, // item 1
        { 100, 20 }, // item 2
        { 120, 30 }, // item 3
        { 40, 5 }, // item 4
        { 80, 15 } // item 5
    };
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double) items[i].value / (double) items[i].weight;
    }

    //For Time analysis
    auto start = chrono::steady_clock::now();
    double max_value = fractional_knapsack(capacity, items, n);
    auto end = chrono::steady_clock::now();

    cout << "Maximum value that can be obtained = " << max_value << endl;
    cout << "Time taken by algorithm: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
    return 0;
}

