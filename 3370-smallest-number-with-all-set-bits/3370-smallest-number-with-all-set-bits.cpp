class Solution {
public:
    int smallestNumber(int n) {
        long long i = 0;
        long long num = 0;
        while(n != 0){
            num += 1 << i;
            i++;
            n = n >> 1;
        }
        return num;
    }
};
