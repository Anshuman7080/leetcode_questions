class Solution {
    private: 
    int solve(string& s,int start,unordered_set<string>&seen){
        if(start ==s.size()){
            return 0;
        }
        int maxcnt=0;
        
        
        for(int i=start+1;i<=s.size();++i){
            string sub=s.substr(start ,i-start);
            
            if(seen.find(sub)==seen.end()){
                seen.insert(sub);
                maxcnt=max(maxcnt,solve(s,i,seen)+1);
                
                
                seen.erase(sub);
            }
            
        }
        return maxcnt;
    }
public:
   
    int maxUniqueSplit(string s) {
        unordered_set<string>seen;
        
        return solve(s,0,seen);
        
    }
};