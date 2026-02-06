/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minRemoval = function(nums, k) {
    nums.sort((a,b) => a-b);
    let be = 0, en = 0;
    let res = 0;
    for(;en < nums.length; en++)
    {
        while(1)
        {
            if(nums[be] < (nums[en] / k) || (nums[be] == (nums[en]/k) && nums[en] % k != 0) )
                be ++;
            else
                break;
        }
        res = (en-be+1) > res ? (en-be+1):res;
    }
    return nums.length - res;
};

