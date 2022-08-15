#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
int T, n, k;
int main() {
    cin >> T;
    while (T -- ) {
        cin >> n >> k;
        int x;
        for (int i = 1; i <= n; i ++ ) {
            scanf("%d", &x);
            a.push_back(x);
        }
        int maxl = -1;
        int sum = 0;
        sort(a.begin(), a.end());
        int j;
        for (int i = 0; i < n; i ++ ) {
            for (j = i; j < n; j ++ ) {
                sum += a[j];
                if (sum % k != 0) maxl = max(maxl, j - i + 1);
            }
            if (j == n - 1 && sum % k != 0) break;  // 剪枝: j遍历到结尾如果符合,i就不用再遍历
            sum = 0;
        }
        a.clear();
        cout << maxl << endl;
    }
    return 0;
}