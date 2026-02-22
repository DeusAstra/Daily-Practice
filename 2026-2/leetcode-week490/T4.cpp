class Solution {
public:
    long long C(int n, int m) {
        if(m == 1)
            return n;
        if(m == 0)
            return 1;
        if(m < 0 || m > n)
            return 0;
        if(m * 2 > n)
            return C(n, n-m);
        return C(n-1,m-1)*n/m;
    }
    long long calcuInst(int sumUp, int thediff) {
        int diff = abs(thediff);
        long long ans = 0;
        for(int i = 0; i <= (sumUp-diff)/2; i++) {
            ans += C(sumUp, i+diff) * C(sumUp-i-diff, i);
        }
        return ans;
    }
    int calcuPow(long long n, int po) {
        int ans = 0;
        while(n % po == 0) {
            ans++;
            n /= po;
        }
        return ans;
    }
    bool checkOnly235(long long n)
    {
        while(n % 2 == 0)
            n/=2;
        while(n % 3 == 0)
            n/=3;
        while(n % 5 == 0)
            n/=5;
        return n==1;
    }
    int countSequences(vector<int>& nums, long long k) {
        int count[10] = {};
        for(size_t i = 0; i < nums.size(); i ++) {
            count[nums[i]] ++;
        }
        int pow2 = calcuPow(k, 2), pow3 = calcuPow(k, 3), pow5 = calcuPow(k, 5);
        if(checkOnly235(k) == 0)
            return 0;
        long long ans = 0;
        for(int diff6 = max({pow2 - count[2] - 2*count[4], pow3 - count[3], -count[6]}); diff6 <= min({pow2+2*count[4]+count[2],pow3+count[3],count[6]}); diff6 ++) {
            printf("from %d to %d : diff6 get %d\n",max({pow2 - count[2] - 2*count[4], pow3 - count[3], -count[6]}), min({pow2+2*count[4]+count[2],pow3+count[3],count[6]}), diff6);
            for(int diff4 = max(int(ceil((pow2 - diff6 -count[2])/2.0)),-count[4]); diff4 <= min({(pow2 - diff6 + count[2])/2,count[4]}); diff4++) {
                printf("from %d to %d : diff4 get %d\n",max(int(ceil((pow2 - diff6 -count[2])/2.0)),count[4]), min({(pow2 - diff6 + count[2])/2,count[4]}), diff4);
                int diff2 = pow2 - diff6 - diff4*2;
                int diff3 = pow3 - diff6;
                printf("pow of 2: %d\npow of 3: %d\npow of 4: %d\npow of 6:%d\nget:ans=%d\n", diff2,diff3,diff4,diff6,ans);
                if(diff2 < -count[2] || diff2 > count[2] || diff3 < -count[3] || diff3 > count[3])
                    continue;
                ans+=calcuInst(count[2], diff2) * 
                     calcuInst(count[4], diff4) *
                     calcuInst(count[6], diff6) *
                     calcuInst(count[3], diff3);
                printf("ans = %d\n\n",ans);
            }
        }
        ans *= calcuInst(count[5], pow5);
        ans *= pow(3, count[1]);
        return ans;
        return ans;
    }
};