class Solution {
public:
    
    int GCD(int a, int b) {
        if (a == 0) return b;
        return GCD(b % a, a); 
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long lcm = (a * b) / GCD(a, b);
        long long low = min(a, b);
        long long high = low * n;
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long count = mid / a + mid / b - mid / lcm;
            
            if (count < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low % 1000000007;
    }
};
