class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3){
            return s;
        }
        string str = "";
        if(s.length() > 2) {
            str += s[0];
            str += s[1];
        }
        
        for(int i = 2; i < s.length(); i++) {
            if(s[i] == s[i-1] && s[i] == s[i-2]) {
                continue;
            } else {
                str += s[i];
            }
        }
        return str;
    }
};
