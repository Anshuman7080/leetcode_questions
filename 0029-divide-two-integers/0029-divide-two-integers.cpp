


class Solution {
public:
    int divide(int dividend, int divisor) {
       
        if (divisor == 0) return INT_MIN;

        
        if (dividend == divisor) return 1;

    
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        
        unsigned int n = abs(dividend), d = abs(divisor);
        unsigned int ans = 0;

      
        while (n >= d) {
            int count = 0;
            while (n > (d << (count + 1))) count++;
            n -= d << count;
            ans += 1 << count;
        }

       
        if (ans == (1 << 31) && sign == 1) return INT_MAX;

        return sign * ans;
    }
};