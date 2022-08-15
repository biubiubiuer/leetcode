#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
int a, b, n;
int res;
unordered_map<int, int> mp;

int main() {
    scanf("%d%d%d", &a, &b, &n);
    int x = min(a, b), y = max(a, b);
    for (int i = 0; i <= y; i++) {

        if (n - i >= 0 && n - i <= x && mp[n - i] > 0) {
            if (i <= x) {
                res += 2;
            } else {
                res++;
            }
        }
        mp[i]++;
    }
    printf("%d", res);
    return 0;
}