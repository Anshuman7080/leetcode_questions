class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
      
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0];
        
        
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]^nums[i]; 
        }
        
        int i=n-1;
    vector<int>ans;
        while(i>=0){
            ans.push_back((~prefix[i])&(1<<maximumBit)-1);
            i--;
        }
        
        return ans;
        
    }
};