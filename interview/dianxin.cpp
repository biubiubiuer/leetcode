// 给定a、b两种点心的数量，每个礼盒放3个点心，a、b至少各有一个，求最多能包多少个礼盒

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
int n, m;
int dp[N][N];  // dp[i][j]: maxv of "a left i and b left j"
int main()
{
    cin >> n >> m;
    dp[1][2] = 1, dp[2][1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        for (int j = 2; j <= m; j ++ )
        {
            dp[i][j] = max(max(dp[i-2][j-1], dp[i-1][j-2]) + 1, max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]));
        }
    }

    cout << dp[n][m] << endl;

    return 0;

}