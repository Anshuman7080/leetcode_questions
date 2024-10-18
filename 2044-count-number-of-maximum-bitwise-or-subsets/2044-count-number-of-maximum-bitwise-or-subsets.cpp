class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& arr, vector<int>& set, int index) {
        arr.push_back(set); 
        
        for (int i = index; i < nums.size(); i++) {
            set.push_back(nums[i]);
            solve(nums, arr, set, i + 1);
            set.pop_back();
        }
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> set;
        
        solve(nums, arr, set, 0);
        
        int max_or = 0;
        unordered_map<int, int> mapi;
        
        for (const auto& subset : arr) {
            int temp = 0;
            for (int num : subset) {
                temp |= num;
            }
            
            mapi[temp]++;
            max_or = max(max_or, temp);
        }
        
        return mapi[max_or];
    }
};
