//6.3 Implement Subset sum problem with backtracking approach and perform its empirical analysis.

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void subsetSum(vector<int>& nums, int target, int currSum, vector<int>& currSet, vector<vector<int>>& result, int startIndex) {
    if (currSum == target) {
        result.push_back(currSet);
        return;
    }

    for (int i = startIndex; i < nums.size(); i++) {
        if (currSum + nums[i] <= target) {
            currSet.push_back(nums[i]);
            subsetSum(nums, target, currSum + nums[i], currSet, result, i + 1);
            currSet.pop_back();
        }
    }
}

vector<vector<int>> subsetSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    vector<int> currSet;

    subsetSum(nums, target, 0, currSet, result, 0);

    return result;
}

int main() {
    // Sizes of input arrays
    vector<int> sizes = {10, 15, 20, 25, 30};

    for (auto& size : sizes) {
        vector<int> nums(size);
        // Populate array with random integers
        for (int i = 0; i < size; i++) {
            nums[i] = rand() % 100;
        }

        int target = rand() % (size * 20) + 1; // Choose random target sum

        auto start = chrono::steady_clock::now(); // Start timer

        vector<vector<int>> result = subsetSum(nums, target);

        auto end = chrono::steady_clock::now(); // End timer

        auto diff = end - start;
        cout << "Input size: " << size << ", Target sum: " << target << ", Time taken: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    }

    return 0;
}

