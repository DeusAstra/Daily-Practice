class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int gap=0;
        while(n % 2 == 0)
            n/=2;
        while(n != 0) {
            if(n % 2 == 1) {
                ans = max(ans,gap);
                gap = 1;
            }
            else {
                gap ++;
            }
            n /= 2;
        }
        return ans;
    }
};