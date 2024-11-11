
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
    vector<int> primes;
    for (int i = 1; i <= 1000; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    
    for (int i = nums.size() - 2; i >= 0; i--) {
        int j = 0;
        while (nums[i] >= nums[i + 1] && j < primes.size()) {
           
            if(nums[i]-primes[j] >=nums[i+1]){
                  j++;
            }
            else{
                nums[i]=nums[i]-primes[j];
            }
          
           
        }
        if (nums[i] <= 0 || j >= primes.size()) {
            return false;
        }
    }
    return true;
}



};

