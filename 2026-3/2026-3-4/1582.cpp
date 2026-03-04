class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> columnTag(mat.size(),-1);
        vector<int> rowTag(mat[0].size(),-1);
        
        printf("%d %d\n",mat.size(),mat[0].size());

        for(size_t i = 0; i < mat.size(); i++) {
            for(size_t j = 0; j < mat[i].size(); j++) {
                printf("%d ",mat[i][j]);
                if(mat[i][j] == 0 )
                    continue ;
                else if(mat[i][j] == 1 ) {
                    if(columnTag[i] == -1)
                        columnTag[i] = j;
                    else
                        columnTag[i] = -2;
                    if(rowTag[j] == -1)
                        rowTag[j] = i;
                    else
                        rowTag[j] = -2;
                }
            }
            printf("\n");
        }

        int ans = 0;

        for(size_t i = 0; i < mat.size(); i++)  {
            if(columnTag[i] >= 0 && rowTag[columnTag[i]] == i)
                ans ++;
        }
        return ans;
    }
};