class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int pro=1;
        int start=0;
        int end=0;
        int cnt=0;
        while(end<nums.size()){
            pro*=nums[end];
            
            while(pro >=k && end>=start){
                pro/=nums[start];
                start++;
            }
            cnt+=end-start+1;
            end++;
        }
        
        return cnt;
    }
};