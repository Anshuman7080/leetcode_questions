
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mapi;
        int cnt = 0;
        mapi[0] = 1;  

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

           
            if (rem < 0) {
                rem += k;
            }

            cnt += mapi[rem];
            mapi[rem]++;
        }

        return cnt;
    }
};

