class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int total=0;
        unordered_map<int,int>fre;
        
        int start=0,end=0,n=nums.size(),count=0;
        
        while(end<n){
            fre[nums[end]]++;
            
            if(fre[nums[end]]==1){
                count++;
            }
            
            while(count==k){
                total+=n-end;
                fre[nums[start]]--;
                
                if(fre[nums[start]]==0){
                    count--;
                }
                
                
                start++;
            }
            
            
            
            
            
            end++;
            
        }
        
        
        start=0,end=0,count=0;
        fre.clear();
        k++;
        
        
        
        
         while(end<n){
            fre[nums[end]]++;
            
            if(fre[nums[end]]==1){
                count++;
            }
            
            while(count==k){
                total-=n-end;
                fre[nums[start]]--;
                
                if(fre[nums[start]]==0){
                    count--;
                }
                
                
                start++;
            }
            
            
            
            
            
            end++;
            
        }
        
        
        
        
        return total;
        
        
        
    }
};