#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int T;
int s, m;
const int N = 19;
int l0[N], l1[N];
int len0, len1;

inline int xor_by_dig(int x)
{
    while (x) {
        if (x & 1) l0[len0++] = 1;
        else l1[len1++] = 0;

        x >>= 1;
    }
}

int main()
{
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d%d", &s, &m);

        memset(l0, -1, sizeof(l0));
        memset(l1, -1, sizeof(l1));
        len0 = 0, len1 = 0;



    }

    return 0;
}