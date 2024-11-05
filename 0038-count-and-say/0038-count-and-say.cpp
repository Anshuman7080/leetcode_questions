


class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        if (n == 1) {
            return str;
        }
        
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int cnt = 1;
            
            for (int j = 1; j <= str.length(); j++) {
                if (j < str.length() && str[j] == str[j - 1]) {
                    cnt++;
                } else {
                    temp += to_string(cnt);
                    temp += str[j - 1];
                    cnt = 1;
                }
            }
            
            str = temp;
        }
        
        return str;
    }
};
