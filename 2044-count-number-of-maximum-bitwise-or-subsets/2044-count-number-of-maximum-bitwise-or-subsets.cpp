class Solution {
public:
    void solve(vector<int>& nums, int& max_or, int index, int local, int& cnt) {
        if (local == max_or) {
            cnt++;
        }
        
        for (int i = index; i < nums.size(); i++) {
            solve(nums, max_or, i + 1, local | nums[i], cnt);
        }
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;
        }
        
        int cnt = 0;
        solve(nums, max_or, 0, 0, cnt);
        
        return cnt;
    }
};
