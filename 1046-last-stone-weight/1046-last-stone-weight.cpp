class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }
        
      
        std::priority_queue<int> q;
        
        for (int i = 0; i < stones.size(); i++) {
            q.push(stones[i]);
        }
        
        while (q.size() > 1) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            
            if (first != second) {
                q.push(first - second);
            }
        }
        
        if (q.empty()) {
            return 0;
        } else {
            return q.top();
        }
    }
};