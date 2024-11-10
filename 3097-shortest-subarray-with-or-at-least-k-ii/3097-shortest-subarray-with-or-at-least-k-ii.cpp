


class Solution {
public:
    void solve(long long n, vector<long long>& bits, int f) {
        int i = 0;
        while (n > 0) {
            if (n & 1) {
                bits[i] += f;
            }
            i++;
            n /= 2;
        }
    }

    bool value(const vector<long long>& bits, int k) {
        long long ans = 0;
        long long p = 1;
        for (int i = 0; i < 64; i++) {
            if (bits[i]) {
                ans += p;
            }
            p = p << 1;
        }
        return ans >= k;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0;
        int ans = n + 2;
        vector<long long> bits(64, 0);
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            solve(nums[i], bits, 1);
            while (st <= i && value(bits, k)) {
                ans = min(ans, i - st + 1);
                solve(nums[st], bits, -1);
                st++;
            }
        }

        if (ans > n) {
            return -1;
        }
        return ans;
    }
};

