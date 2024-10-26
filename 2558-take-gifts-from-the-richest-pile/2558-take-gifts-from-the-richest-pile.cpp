

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<long long >max_heap;
        
        for(int i=0;i<gifts.size();i++){
            max_heap.push(gifts[i]);
        }
        
        
        for(int i=0;i<k;i++){
            long long num=max_heap.top();
            max_heap.pop();
            
            max_heap.push(int(sqrt(num)));
        }
        long long sum=0;
        
        while(!max_heap.empty()){
            sum+=max_heap.top();
            max_heap.pop();
        }
        
        
        return sum;
    }
};