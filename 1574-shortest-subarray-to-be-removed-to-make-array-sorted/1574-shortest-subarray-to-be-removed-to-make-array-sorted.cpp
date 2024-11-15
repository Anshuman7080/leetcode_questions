class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        // Find the first decreasing element from the left
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        // If the entire array is non-decreasing, return 0
        if (left == n - 1) {
            return 0;
        }
        
        // Find the first decreasing element from the right
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        // Calculate the minimum length to remove
        int result = min(n - left - 1, right);
        
        // Try to merge the left and right parts
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};
