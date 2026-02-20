#include<cstdio>
#include <iostream>
#include <set>
int main()
{
    std::set<int> s;
    s.insert(1);
    printf("%d\n", s.size());
    s.insert(1);
    printf("%d\n", s.size());
    s.insert(2);
    printf("%d\n", s.size());
    return 0;
}