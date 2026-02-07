int minimumDeletions(char* s) {
    int counta = 0;
    int countb = 0;
    int length = strlen(s);
    for(int i = 0; i < length; i ++)
    {
        if(s[i] == 'a')
            counta ++;
        else
            countb ++;
    }
    int nowa = 0, nowb = 0;
    int mindelete = counta;
    int nowdelete = 0;
    for(int i = 0; i < length; i ++)
    {
        if(s[i] == 'a')
            nowa ++;
        else
            nowb ++;
        nowdelete = counta + nowb - nowa;
        mindelete = nowdelete < mindelete ? nowdelete : mindelete;
    }
    return mindelete;
}
/*
务必使用length来储存strlen(s)! 如果判断条件改成 i < strlen(s)，则会超时

在C语言中，字符串以\0结尾，strlen(s)函数需要遍历字符串直到遇到\0，是O(n)操作。如果每次循环都调用strlen(s)，那么整个循环的时间复杂度就是O(n^2)。

而在JavaScript中，字符串的length属性是一个整数，每次访问都是O(1)操作，因为字符串对象在创建时就已经存储了长度值。因此，循环条件i < s.length在每次迭代时只是读取一个属性值，不会重新计算字符串长度。

因此JS中可以放心大胆地.length，而C中则需要改成s[i] != 0（已通过），或者用length来存储（已通过），而不能使用i < strlen(s) （TLE）
*/