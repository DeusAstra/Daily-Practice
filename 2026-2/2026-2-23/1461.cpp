class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int> Substring;
        Substring.clear();
        int nowString = 0;
        int MOD = 1;
        if(s.size() <= k ) {
            return 0;
        }
        for(size_t i = 0; i < k; i++) {
            nowString = nowString*2 + s[i] - '0';
            MOD *= 2;
        }
        Substring.insert(nowString);
        for(int i = k; i < s.size(); i++) {
            nowString = nowString*2 + s[i] - '0';
            nowString %= MOD;
            printf("%d ",nowString);
            Substring.insert(nowString);
        }
        printf("\n");
        for(int i:Substring)
        {
            printf("%d ",i);
        }
        printf("\n%d\n",Substring.size());
        if(Substring.size() == MOD)
            return 1;
        else
            return 0;
    }
};