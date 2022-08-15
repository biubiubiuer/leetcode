// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// using namespace std;

// const int N = 100 * 100 + 10; // 多重背包拆成0-1背包
// int a[N], b[N], t = 0, n, m, f[N], v, w, s;

// signed main()
// {
//     cin >> n >> m;
//     while (n -- ) 
//     {
//         cin >> v >> w >> s;
//         while (s -- )
//         {
//             a[++ t ] = v;
//             b[t] = w;
//         } // 死拆，把多重背包拆成01背包
//     }
//     for (int i = 1; i <= t; i ++ ) 
//         for (int j = m; j >= a[i]; j -- )
//             f[j] = max(f[j], f[j - a[i]] +b[i]);

//     cout << f[m] << endl;
//     return 0;
// }


// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// using namespace std;

// const int N = 2010;

// int n, m, v, w, s, f[N];

// struct Good
// {
//     int v, w;
// };

// vector<Good> goods;

// signed main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++ )
//     {
//         cin >> v >> w >> s;
//         for (int k = 1; k <= s; k <<= 1)
//         {
//             s -= k;
//             goods.push_back({v * k, w * k});
//         }
//         if (s > 0) goods.push_back({v * s, w * s});
//     }

//     for (auto good : goods) 
//         for (int j = m; j >= good.v; j -- ) 
//             // 能够二进制优化的原因: 如果放进某物品i能让总价值变大, 那么尽快找到物品i能放入的最多个数k即可, --> 二进制逼近比暴力逼近快
//             f[j] = max(f[j], f[j - good.v] + good.w);

//     cout << f[m] << endl;
//     return 0;
// }



/*

f[j] = f[j - v] + w, f[j - 2 * v] + 2 * w, ... , f[j - k * v] + k * w

f[j + v] = f[j] + w, f[j - v] + 2 * w, f[j - 2 * v] + 3 * w, ... , f[j - k * v] + (k + 1) * w

发现, 与传统单调队列问题(lc239)相比, 滑动窗口内的值是在变化的, 但好在偏移量都是固定值, 所以比较的时候可以偏移后再比较

f[0] 
f[v] - 1 * w
f[2 * v] - 2 * w

第一重循环: 枚举所有余数
第二重循环: 枚举此余数队列中的所有数(单调队列优化)

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

const int N = 20010;

int n, m;
int v, w, s;
int f[N], g[N], q[N];

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) 
    {
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f);

        for (int j = 0; j < v; j ++ ) 
        {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v)
            {
                f[k] = g[k];
                if (hh <= tt && k - s * v > q[hh]) hh ++ ;
                if (hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt -- ;
                q[++ tt ] = k;
            }
        } 
    }
    
    cout << f[m] << endl;
    return 0;
}
