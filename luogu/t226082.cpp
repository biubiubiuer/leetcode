#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int mod = 998244353, N = 5e5 + 10;
int n, m;
int sx[N];
queue<int> q;
ll res;


struct island {
    int li, ri, hi;
} isl[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &isl[i].li, &isl[i].ri, &isl[i].hi);

    sort(isl + 1, isl + m + 1, [](auto const &a, auto const &b) {
        return a.hi > b.hi;
    });

    // solution
    cout << "n: " << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << 1 << endl;
        scanf("%d", &sx[i]);
        res++;
        q.push(sx[i]);
        while (!q.empty()) {
            for (int j = 1; j <= m; j++) {
                if (q.front() >= isl[j].li && q.front() <= isl[j].li) {
                    res++;
                    q.pop();
                    q.push(isl[j].li), q.push(isl[j].ri);
                } else {
                    q.pop();
                }
            }
        }
    }

    cout << res % mod << endl;
    return 0;
}