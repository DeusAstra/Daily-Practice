class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size() <= 2)
            return s;
        vector<string>piece;
        piece.clear();
        int sum = 0, bg = 0;
        for(size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
                sum ++;
            else
                sum --;
            if(sum == 0 && !(i == s.size()-1 && bg == 0))
            {
                piece.push_back(makeLargestSpecial(s.substr(bg,i-bg+1)));
                bg = i+1;
            }
        }
        if(piece.empty())
        {
            cout<<s;
            printf("  cut occured\n");
            return '1'+makeLargestSpecial(s.substr(1,s.size()-2))+'0';
        }
        else
        {
            sort(piece.begin(),piece.end(),[](const std::string& a, const std::string& b) {
                return a > b;   // 降序
                });
            string ans = "";
            for(auto &i:piece)
                ans+=i;
            return ans;
        }
    }
};

/*
取string类型的子字符串:substr
string s;
s.substr(start, length);
start默认为0，length默认为s.size()-start
返回从start开始length个字符的拷贝
*/