#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxLength = -1;

        for (int i = 0; i < nums.size(); i++) {
            long long current = nums[i];
            int length = 1;

            while (numSet.find(current * current) != numSet.end()) {
                current = current * current;
                length++;
            }

            if (length >= 2) {
                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};

