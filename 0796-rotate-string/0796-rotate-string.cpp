


class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        
        for(int i=0; i<s.length(); i++){
            char a = s[0];
            s.erase(s.begin());
            s += a;
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};
