#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 1e5 + 10;
char vs[N][N];
char s[N], path[N];
unordered_map<char, int> mp;
int T;
int si, sj;

void dfs(string s, int begin, int size) {
    if (strlen(path)) {
        memcpy(vs[si++], path, sizeof vs);
        sj = 0;
    }
    for (int i = begin; i < size; i++) {
        path[sj++] = s[i];
        dfs(s, i + 1, size);
        memset(path, 0, sizeof path);
    }
    memset(path, 0, sizeof path);
}

int main() {
    while (T--) {
        scanf("%s", s);
        int n = strlen(s);
        dfs(s, 0, n);
        int res = 0;
        for (int i = 0; i < si; i++) {
            int len = strlen(vs[i]);
            for (int j = 0; j < len; j++)
                mp[vs[i][j]]++;
            for (int j = 0; j < len; j++)
                if (mp[vs[i][j]] == 1) res++;
            mp.clear();
        }
        cout << res << endl;
    }

    return 0;
}