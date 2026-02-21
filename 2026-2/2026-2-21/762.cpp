// #include<cmath>
class Solution {
public:
    bool isPrime(int p) {
        for(int i = 0; i <= int(sqrt(p)); i++) {
            if(p%i == 0)
                return 0;
        }
        return 1;
    }
    int countOne(int p) {
        int ans = 0;
        while(p)
        {
            if(p % 2 == 1)
                ans++;
            p/=2;
        }
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i < right; i++) {
            if(isPrime(countOne(i)) == 1) {
                ans++;
            }
        }
        return ans;
    }
};