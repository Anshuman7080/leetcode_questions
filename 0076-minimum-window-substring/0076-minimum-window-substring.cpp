class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        
        int n=s.length();
        int start=0;
        int end=0;
        int ans=INT_MAX;
        int index=-1;
        int total=t.size();
        
        while(end<s.length()){
            m[s[end]]--;
            if(m[s[end]]>=0)
                total--;
            while(!total && start<=end){
                if(ans> end-start+1){
                    ans=end-start+1;
                    index=start;
                }
                m[s[start]]++;
                if(m[s[start]]>0){
                    total++;
               
                }
                     start++;
            }
            end++;
        }
        
        if(index==-1){
            return "";
        }
        
        string str;
        
        for(int i=index;i<index+ans;i++){
            str+=s[i];
        }
        
        return str;
    }
};