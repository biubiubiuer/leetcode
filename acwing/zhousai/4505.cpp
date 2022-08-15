//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 2e5+10;
//int n;
//int a[N];
//int odd_num, even_num;
//int odd[N], even[N];
//int odd_dis[N], even_dis[N];
//
//struct window
//{
//    int l, r, len;
//} win[2];
//
////inline int abs(int a, int b)
////{
////    int x = a - b;
////    return x >= 0 ? x : -x;
////}
//inline bool is2x(int x)
//{
//    while (!(x & 1)) x >>= 1;
//    if (x == 1) return true;
//    else return false;
//}
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i ++ )
//    {
//        scanf("%d", &a[i]);
//        if (a[i] & 1)
//        {
//            odd[++odd_num] = a[i];
//        }
//        else
//        {
//            even[++even_num] = a[i];
//        }
//    }
//
//    sort(odd+1, odd+1+odd_num), sort(even+1, even+1+even_num);
//
//    int idx = 1;
//    for (int i = 2; i <= odd_num; i ++ )
//    {
//        odd_dis[idx ++ ] = odd[i] - odd[i - 1];
//    }
//    idx = 1;
//    for (int i = 2; i <= even_num; i ++ )
//    {
//        even_dis[idx ++ ] = even[i] - even[i - 1];
//    }
//
//    // sliding window
//    int l = 1, r = 1, maxl = 0;
//    while (r <= odd_num - 1)
//    {
//        if (is2x(odd_dis[r]))
//        {
//            if (r - l + 1 > maxl)
//            {
//                win[0].l = l, win[0].r = r, win[0].len = r - l + 1;
//                maxl = r - l + 1;
//            }
//            r ++ ;
//        }
//        else
//        {
//            l = r = r + 1;
//        }
//    }
//
//    l = 1, r = 1, maxl = 0;
//    while (r <= even_num - 1)
//    {
//        if (is2x(even_dis[r]))
//        {
//            if (r - l + 1 > maxl)
//            {
//                win[1].l = l, win[1].r = r, win[1].len = r - l + 1;
//                maxl = r - l + 1;
//            }
//            r ++ ;
//        }
//        else
//        {
//            l = r = r + 1;
//        }
//    }
//
//    if (win[0].len < win[1].len)
//    {
//        cout << win[0].len << endl;
//        for (int i = win[0].l; i <= win[0].r + 1; i ++ )
//        {
//            printf("%d ", odd[i]);
//        }
//    }
//    else
//    {
//        cout << win[1].len << endl;
//        for (int i = win[1].l; i <= win[1].r + 1; i ++ )
//        {
//            printf("%d ", even[i]);
//        }
//    }
//
//    return 0;
//
//}



#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010, M = 1999997, INF = 0x3f3f3f3f;

int n;
int q[N], h[M];

inline int find(int x)
{
    int t = (x % M + M) % M;
    while (h[t] != INF && h[t] != x)
        if ( ++ t == M)
            t = 0;
    return t;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    sort(q, q + n);

    memset(h, 0x3f, sizeof h);

    int res[3], s[3];
    int rt = 0, st = 0;
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j <= 30; j ++ )
        {
            int d = 1 << j;
            s[0] = q[i], st = 1;
            for (int k = 1; k <= 2; k ++ )
            {
                int x = q[i] - d * k;
                if (h[find(x)] == INF) break;
                s[st ++ ] = x;
            }
            if (rt < st)
            {
                rt = st;
                memcpy(res, s, sizeof s);
                if (rt == 3) break;
            }
        }
        if (rt == 3) break;
        h[find(q[i])] = q[i];
    }

    cout << rt << endl;
    for (int i = 0; i < rt; i ++ )
        cout << res[i] << ' ';
    cout << endl;

    return 0;
}