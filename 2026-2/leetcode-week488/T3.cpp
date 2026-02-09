class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        std::multiset<int> ms;
        int l = 0, r = 0;
        long long count = 0;
        int numsSize = nums.size();
        while(r < numsSize)
        {
            ms.insert(nums[r]);
            while(l <= r)
            {
                if(((long long)(*ms.rbegin() - *ms.begin())) * (r-l+1) > k)
                {
                    ms.erase(ms.find(nums[l]));
                    l++;
                }
                else
                    break;
            }
            // printf("l = %d, r = %d : ", l ,r);
            // for(int p = 0; p < r - l + 1; p ++)
            // {
            //     printf("%d ",ms[p]);
            // }
            // printf("\n");
            count += (long long)(r - l + 1);
            r++;
        }
        // for(int i = 0; i < numsSize; i++)
        // {
        //     printf("%d ",maxlen[i]);
        // }
        // printf("\n");
        return count;
    }
};