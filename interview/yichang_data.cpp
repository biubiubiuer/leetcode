#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105;
int a[N], lv[N], rv[N];
int n;
int res = N + 2;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    for (int i = 2; i <= n - 1; i ++ ) lv[i] += lv[i-1] + a[i-1] >= 0 ? 1 : 0;
    for (int i = n - 1 ; i >= 2; i -- ) rv[i] += rv[i+1] + a[i+1] <= 0 ? 1 : 0;

    for (int i = 2; i <= n - 1; i ++ ) res = min(res, lv[i] + rv[i]);

    cout << res << endl;
    return 0;

}