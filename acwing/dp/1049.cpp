#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

const int N = 1e5+5;

int T, n, a[N], f[N][2]; // 0- 不偷, 1- 偷

signed main()
{

    cin >> T;
    while (T -- ) 
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        for (int i = 1; i <= n; i ++ ) 
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + a[i];
        }

        cout << max(f[n][0], f[n][1]) << endl;

    }

    return 0;
}