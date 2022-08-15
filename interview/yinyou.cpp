#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 12, M = 1e5+5;
const int INF = 0x3f3f3f3f;

int n, m, bomb[M];
int dp[M][N]; // 当前游戏持续到第 i 秒, 小美的指针现在指向了第 j 个房间

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) cin >> bomb[i];

    memset(dp, INF, sizeof dp);
    dp[1][1] = 0;
    for (int i = 2; i <= m; i ++ ) 
    {
        for (int j = 1; j <= n; j ++ )
        {
            if (bomb[i] == j) continue;
            for (int k = 1; k <= n; k ++ )
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j == k ? 0 : 1));
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i ++ ) ans = min(ans, dp[m][i]);
    cout << ans << endl;

    return 0;
}