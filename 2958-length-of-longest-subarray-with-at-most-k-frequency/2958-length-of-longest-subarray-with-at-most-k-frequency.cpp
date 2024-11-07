


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        unordered_map<int, int> mapi;
        int len = 0;
        
        while (end != nums.size()) {
            mapi[nums[end]]++;
            
            while (mapi[nums[end]] > k) {
                mapi[nums[start]]--;
                if (mapi[nums[start]] == 0) {
                    mapi.erase(nums[start]);
                }
                start++;
            }
            
            len = max(len, end - start + 1);
            end++;
        }
        
        return len;
    }
};

