// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// using namespace std;

// const int N = 1005;
// int v[N], w[N];
// int n, m;
// int f[N][N];
// //f[i][j]: j体积下前i个物品的最大价值

// signed main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    
//     for (int i = 1; i <= n; i ++ ) 
//         for (int j = 1; j <= m; j ++ ) 
//         {
//             if (j >= v[i])
//                 f[i][j] = max(f[i - 1][j], f[i-1][j - v[i]] + w[i]);
//             else f[i][j] = f[i - 1][j];
//         }
        
//     cout << f[n][m] << endl;
//     return 0;
// }


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

const int N = 1005;
int v[N], w[N];
int n, m;
int f[N]; // [][] -> []
// f[j]: j 体积下最大值

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++ ) 
        for (int j = m; j >= v[i]; j -- ) 
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    return 0;
}