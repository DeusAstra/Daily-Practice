class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        int en = 0;
        int be = 0;
        int res = 0;
        for(en = 0; en < numsSize; en++)
        {
            while(1)
            {
                if(nums[be] < (int)(nums[en] / k) || (nums[be] == (int)(nums[en]/k) && nums[en] % k != 0) )
                    be ++;
                else
                    break;
            }
            res = (en-be+1) > res ? (en-be+1):res;
        }
        return numsSize - res;
    }
};
/*
qsort后双指针移动i,j使得i到j平衡，前一步为nlog(n)，后一步n
懒得写了，冒泡n^2
然后C就爆时间了，换成C++用sort写
另外需要注意nums[]*k可能会爆int，需要用long long或者用除法
*/