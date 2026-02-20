class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> count;
        count.clear();
        int curr = 1;
        int ans = 0;
        for(size_t i = 1; i < s.size(); i++)
        {
            if(s[i] != s[i-1])
            {
                count.push_back(curr);
                curr = 1;
            }
            else
            {
                curr++;
            }
        }
        count.push_back(curr);
        for(size_t i = 1; i < count.size(); i++)
        {
            ans += min(count[i],count[i-1]);
        }
        return ans;
    }
};