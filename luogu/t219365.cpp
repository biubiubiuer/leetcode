#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int a[N];
struct lim
{
    int li, lj, x, y;
} lim[N];
int n, k, q;

int main()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= q; i ++ )
    {
        scanf("%d%d%d%d", &lim[i].li, &lim[i].lj, &lim[i].x, &lim[i].y);
    }

    // dp???

}