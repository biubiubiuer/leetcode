#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

const int N = 6010;

int n, w[N];
int  h[N], e[N], ne[N], idx;
bool st[N]; // st : has_father
int f[N][2];
// FSM(状态机)
// f[i][0]: 不选根max, f[i][1]: 选根max

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
    f[u][1] = w[u];
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ ) 
    {
        int a, b;
        cin >> a >> b;
        add(b, a);
        st[a] = true;
    }

    int root = 1;
    while (st[root]) root ++ ;

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}