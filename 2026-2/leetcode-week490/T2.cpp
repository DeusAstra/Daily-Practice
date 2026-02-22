#include<cstdio>
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int mul[10];
        mul[0] = 1;
        for(int i = 1; i <= 9; i++) {
            mul[i] = mul[i-1] * i;
        }
        int nBit[10],sumBit[10];
        for(int i = 0; i <= 9; i++) {
            nBit[i] = sumBit[i] = 0;
        }
        int sum = 0,nowBit;
        while(n!=0) {
            nowBit = n % 10;
            sum += mul[nowBit];
            nBit[nowBit] ++;
            n/=10;
        }
        while(sum != 0) {
            nowBit = sum % 10;
            sumBit[nowBit] ++;
            sum /= 10;
        }
        for(int i = 0; i <= 9; i++) {
            if(nBit[i] != sumBit[i])
                return 0;
        }
        return 1;
    }
};
int main() {
    Solution s;
    int n;
    scanf("%d",&n);
    printf("%d\n",s.isDigitorialPermutation(n));
    return 0;
}