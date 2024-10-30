class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis(n, 1), lds(n, 1);

        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

       
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (arr[i] > arr[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

       
        int maxMountainLen = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxMountainLen = max(maxMountainLen, lis[i] + lds[i] - 1);
            }
        }

       
        return n - maxMountainLen;
    }
};
