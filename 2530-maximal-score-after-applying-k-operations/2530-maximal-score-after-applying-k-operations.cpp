class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }

        long long sum = 0;
        while (k--) {
            long long value = q.top();
            sum += q.top();
            q.pop();
            q.push((value + 2) / 3); 
        }

        return sum;
    }
};
