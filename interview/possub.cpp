#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 17;
int a[N];
int dp[N][N];
int n, res;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
    {
        scanf("%d", &a[i]);
        if (a[i] == -1) 
        {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][0];
        }
        else 
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + 1;
        }
        res += dp[i][1];
    }

    cout << res << endl;
    
    return 0;
}