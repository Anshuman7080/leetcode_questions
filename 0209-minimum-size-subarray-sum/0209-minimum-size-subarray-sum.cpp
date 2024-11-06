class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int prefixSum=0;
        int start=0;
        int end=0;
        int size=INT_MAX;
        
       while(end!=nums.size()){
            prefixSum+=nums[end];
            end++;
            
            if(prefixSum>=target){
                size=min(size,end-start+1);
            }
            
            while(prefixSum >=target){
                prefixSum-=nums[start];
                start++;
                 size=min(size,end-start+1);
            }
             
            
        }
        if(size==INT_MAX){
            return 0;
        }
        
        return size;
    }
};