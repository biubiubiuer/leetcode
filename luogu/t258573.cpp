// WA
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int s[5];
int T;

inline bool case1(int s[])
{
    for (int i = 2; i <= 3; i ++ )
        if (s[i] + 1 == s[i-1] && s[i] + 2 == s[i-2]) return true;
    return false;
}

inline bool is_dis(int a, int b)
{
    if (abs(a - b) > 0 && abs(a - b) <= 2) return true;
    return false;
}

inline bool case2(int s[])
{
    if (s[0] == s[1] && is_dis(s[2], s[3]) || is_dis(s[0], s[1]) && s[2] == s[3]) return true;
    return false;
}

int main()
{
    cin >> T;
    while (T -- )
    {
        for (int i = 0; i < 4; i ++ ) scanf("%d", &s[i]);

        sort(s, s+4, [](auto a, auto b) { return a > b;});

        if (case1(s)) printf("%d\n", 1);
        else if (case2(s)) printf("%d\n", 1);
        else printf("%d\n", 0);

    }
    return 0;
}