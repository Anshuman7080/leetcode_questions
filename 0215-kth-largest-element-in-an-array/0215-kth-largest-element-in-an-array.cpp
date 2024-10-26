class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<long long>q;
        
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        
        
       for(int i=0;i<k-1;i++){
           q.pop();
       }
        
        return q.top();
        
        
    }
};