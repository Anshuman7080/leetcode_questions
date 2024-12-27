
class Solution {
public:
    int checker(vector<int>& nums, int dist) {
        int n = nums.size();
        int l = 0;
        int p = 0;
        for(int r = 0; r < n; r++){
            while(nums[r] - nums[l] > dist) l++;
            p += r - l;
        }
        return p;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (checker(nums, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};