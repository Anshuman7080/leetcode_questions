class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(),nums.end());
        long long cnt1=0;
    long long cnt2=0;
        
    long long st=0;
        long long end=nums.size()-1;
        
        while(st<end){
            if(nums[st]+nums[end]<=upper){
                cnt1+=end-st;
                st++;
                
            }else{
                end--;
            }
        }
        
        st=0;
        end=nums.size()-1;
        
        while(st<end){
            if(nums[st]+nums[end]<lower){
                cnt2+=end-st;
                st++;
                
            }else{
                end--;
            }
        }
        
        
        return cnt1-cnt2;
        
        
    }
};