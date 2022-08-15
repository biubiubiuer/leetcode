#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 22, M = 45;

int n, m;
int a[N], b[N], vis[M];
int ans;

void dfs(int x, int cur) 
{
    if (x == n + 1) { ans = max(ans, cur); return ; }

    if (!vis[a[x]] && !vis[b[x]]) // choose
    {
        vis[a[x]] = vis[b[x]] = 1;
        dfs(x + 1, cur + 1);
        vis[a[x]] = vis[b[x]] = 0;
    }

    dfs(x + 1, cur); // not choose
}

signed main() 
{
    for (int i = 0; i <= n; i ++ ) scanf("%d %d", &a[i], &b[i]);

    dfs(1, 0);
    cout << ans << '\n';
    return 0; 
}
