class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mapi;
        
        mapi[0]=1;
        
        int prefixsum=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(mapi.count(prefixsum-k)){
                total+=mapi[prefixsum-k];
            }
            mapi[prefixsum]++;
        }
        
        
        return total;
        
        
    }
};