
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> ps(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            ps[i] = ps[i - 1] + (nums[i - 1] == 1 ? 1 : -1);
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 1; i <= nums.size(); i++) {
            if (ps[i] == 0) {
                ans = max(ans, i);
            } else if (mp.find(ps[i]) != mp.end()) {
                ans = max(ans, i - mp[ps[i]]);
            } else {
                mp[ps[i]] = i;
            }
        }
        return ans;
    }
};

