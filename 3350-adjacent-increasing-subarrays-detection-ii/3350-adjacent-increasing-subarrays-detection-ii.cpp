


class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<pair<int,int>> p;
        int start = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                p.push_back({start, i});
                start = i + 1;
            }
        }
        p.push_back({start, nums.size() - 1});

        int len1 = 0;
        for (int i = 0; i < p.size() - 1; i++) {
            if (p[i].second + 1 == p[i + 1].first) {
                len1 = max(len1, min(p[i].second - p[i].first + 1, p[i + 1].second - p[i + 1].first + 1));
            }
        }

        int len2 = 0;
        for (int i = 0; i < p.size(); i++) {
            len2 = max(len2, (p[i].second - p[i].first + 1) / 2);
        }

        return max(len1, len2);
    }
};

