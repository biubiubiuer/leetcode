#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);

    int l = 0, r = h.size() - 1;
    int maxv = INT32_MIN;
    for (int i = l; i < r; i ++ ) {
        if (i + 1 < r && h[i + 1] <= h[i]) continue;
        maxv = max(maxv, (r - i) * max(h[i], h[r]));
    }

    for (int j = r; j > l; j -- ) {
        if (j - 1 > l && h[j - 1] <= h[j]) continue;
        maxv = max(maxv, (j - l) * max(h[j], h[l]));
    }

    cout << maxv << endl;
    return 0;
}