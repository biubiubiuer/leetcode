#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 4005;
int a[N], n, res;

int main()
{
    scanf("%d", &n);
    for (int ii = 1; ii <= n; ii ++ ) scanf("%d", &a[ii]);

    // 移项: a[i] + a[k] = 3 * a[j] && i < j < k

    if (n < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    int x, y;
    for (int k = 2; k <= n; k ++ )
        for (int j = 1; j < k; j ++ )
            for (int i = 0; i < j; i ++ )
            {
                x = a[i] + a[k], y = 3 * a[j];
                if (x == y) res ++ ;
            }

    cout << res << endl;

    return 0;
}