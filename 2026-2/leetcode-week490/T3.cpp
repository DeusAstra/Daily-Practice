class Solution {
public:
    string maximumXor(string s, string t) {
        int countOne, countZero;
        countOne = countZero = 0;
        for(size_t i = 0; i < t.size(); i++) {
            if(t[i] == '1')
                countOne ++;
            else
                countZero ++;
        }
        string ans = "";
        for(size_t i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                if(countZero > 0) {
                    countZero --;
                    ans+='1';
                }
                else {
                    countOne --;
                    ans+='0';
                }
            }
            else {
                if(countOne > 0) {
                    countOne --;
                    ans+='1';
                }
                else {
                    countZero --;
                    ans+='0';
                }
            }
        }
        return ans;
    }
};