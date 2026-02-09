/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdio.h>
 #include<stdlib.h>
long long* mergeAdjacent(int* nums, int numsSize, int* returnSize)
{
    long long* a = (long long*)malloc(sizeof(long long)*numsSize);
    int s = 0;
    long long l = 0;
    for(int i = 0; i < numsSize; i ++)
    {
        a[s++] = nums[i];
        for(;s >= 2; s --)
        {
            if(a[s-1] == a[s-2])
            {
                a[s-2] *=2;
            }
            else
                break;
        }
    }
    *returnSize = s;
    // printf("s = %d\n",s);
    // for(int i = 0; i < s; i++)
    // {
    //     printf("%lld ",a[i]);
    // }
    // printf("\n");
    return a;
}
int main()
{
    int n;
    scanf("%d",&n);
    int in[20000];
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&in[i]);
    }
    int re;
    long long* a = mergeAdjacent(in,n,&re);
    for(int i = 0; i < re; i++)
    {
        printf("%lld ",a[i]);
    }
}