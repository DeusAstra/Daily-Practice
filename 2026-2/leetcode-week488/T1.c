int dominantIndices(int* nums, int numsSize) {
    int endsum = 0;
    int count = 0;
    for(int i = numsSize - 1; i >= 0; i --)
    {
        if(endsum < nums[i] * (numsSize-i-1))
            count ++;
        endsum += nums[i];
    }
    return count;
}