#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

const int N = 105;

int he[N], e[N], ne[N], tot;
int w[N];
int f[N][N];
int n, q;

void add(int x, int y, int z)
{
    e[tot] = y, w[tot] = z, ne[tot] = he[x], he[x] = tot ++ ;
}

void dfs(int u, int fa)
{
    for (int i = he[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa) continue;
        dfs(v, u);
        for (int j = q; j >= 0; j -- ) // 容量, 划分体积
            for (int k = 0; k <= j - 1; k ++ ) // 价值计算
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + w[i]);
    }
}

signed main()
{
    memset(he, 0xff, sizeof he);

    cin >> n >> q;
    for (int i = 1; i <= n - 1; i ++ ) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << f[1][q] << endl;
    return 0;
}