// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// using namespace std;

// const int N = 50005;

// int n, x, y;
// int a[N];

// /*
// 大于m晋级，其他淘汰
// if m不存在 输出-1
// if m存在多个 输出最低分数线
// 晋级or淘汰人数区间： [x, y]
// */
// signed main()
// {
//     scanf("%d%d%d", &n, &x, &y);
//     for (int i = 1; i <= n ; i ++ ) scanf("%d", &a[i]);
//     sort(a+1, a+n+1);
//     int lnum = 0, rnum = n; // lnum:淘汰， rnum:晋级
//     int i = 1;
    
//     while (i <= n && lnum < x && rnum > y) {
//         lnum ++ , rnum -- ;
//         i ++ ;
//     }
//     if (i > n) {
//         cout << -1 << endl;
//         return 0;
//     }
//     if (lnum >= x && rnum <= y) {
//         cout << a[i] << endl;
//         return 0;
//     }
//     else if (lnum >= x) // but rnum > y
//     {
//         while (i <= n && lnum <= y && rnum > y) {
//             lnum ++ , rnum -- ;
//             i ++ ;
//         }
//         if (i > n || lnum > y) {
//             cout << -1 << endl;
//             return 0;
//         } 
//         else {
//             cout << a[i] << endl;
//             return 0;
//         }
//     }
//     else if (rnum <= y) // but lnum < x
//     {
//         while (i <= n && rnum >= x && lnum < x) {
//             lnum ++, rnum -- ;
//             i ++ ;
//         }
//         if (i > n || rnum < x) {
//             cout << -1 << endl;
//             return 0;
//         }
//         else {
//             cout << a[i] << endl;
//             return 0;
//         }
//     }

    
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

const int N = 50005;
int a[N], n, x, y;

signed main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a+1, a+n+1);
    // 范围
    if (n < x << 1 || n > y << 1) 
    {
        cout << -1 << endl;
        return 0;
    }

    // 二分淘汰人数
    int l = x, r = y + 1, mid;
    while (l < r) 
    {
        mid = (l + r) >> 1;
        if (n - mid >= x || n - mid <= y) r = mid;
    }
    cout << a[l] << endl;
    return 0;
}