var constructTransformedArray = function(nums) {
    let res = [];
    for(let i = 0; i < nums.length; i++)
    {
        res[i] = nums.at((i+nums[i])%nums.length);
    }
    return res;
};