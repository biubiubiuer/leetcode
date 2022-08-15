// #include <iostream>
// #include <stdio.h>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <vector>
// #define ios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

// using namespace std;

// const int N = 107;

// bool col[N], dg[N], udg[N]; // 定义3个数组分别标记行和两条对角线
// int idx = 0;

// vector<vector<string>> res;

// void dfs(int u, int n, vector<string> &s)
// {
//     if (u == n)
//     {
//         res.push_back(s);
//         return;
//     }

//     for (int j = 0; j < n; j++)
//         if (!col[j] && !dg[j+u] && !udg[j-u+n])
//         {
//             col[j] = dg[j+u] = udg[j-u+n] = true;
//             s[u][j] = 'Q';
//             dfs(u+1, n, s);
//             col[j] = dg[j+u] = udg[j-u+n] = false;
//             s[u][j] = '.';
//         }
// }

// vector<vector<string>> solveNQueens(int n)
// {
//     res.clear();
//     vector<string> s(n, string(n, '.'));
//     dfs(0, n, s);
//     return res;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     res = solveNQueens(n);
//     for (int i = 0; i < res.size(); i++)
//         for (int j = 0; j < res[i].size(); j++)
//             cout << res[i][j] << endl;
//     return 0;
// }

// #include <iostream>

// using namespace std;

// const int N = 20;

// int n;
// char g[N][N];
// int path[N];
// bool col[N], dg[N], udg[N];

// void dfs(int u)
// {
//     if (u == n)
//     {
//         for (int i = 0; i < n; i++)
//             puts(g[i]);
//         puts("");
//         return;
//     }

//     for (int i = 0; i < n; i ++ )
//         if (!col[i] && !dg[u + i] && !udg[n - u + i])
//         {
//             g[u][i] = 'Q';
//             col[i] = dg[u + i] = udg[n - u + i] = true;
//             dfs(u + 1);
//             col[i] = dg[u + 1] = udg[n - u + 1] = false;
//             g[u][i] = '.';
//         }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             g[i][j] = '.';
//     dfs(0);
//     return 0;
// }

#include <iostream>
using namespace std;
const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int cnt)
{
    if (y == n)
        y = 0, x++;

    if (x == n)
    {
        if (cnt == n)
        {
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
        }
        return;
    }

    // 不放皇后
    dfs(x, y + 1, cnt);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, cnt + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0, 0, 0);
    return 0;
}
