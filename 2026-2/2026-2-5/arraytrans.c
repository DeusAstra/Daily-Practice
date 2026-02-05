int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++)
    {
        //printf("%d ", (abs(i+nums[i]))%numsSize);
        result[i] = nums[((i+nums[i])%numsSize+numsSize)%numsSize];
    }
    return result;
}
/*
模运算符号规则：
C/C++/Java/JavaScript: 结果符号与被除数相同
Python/Ruby: 结果符号与除数相同
*/