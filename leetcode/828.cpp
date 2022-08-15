#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
vector<string> res;
string path;
unordered_map<char, int> mp;

void dfs(string & s, int begin) {
    if (!path.empty()) {
        res.push_back(path);
    }

    for (int i = begin; i < s.size(); i ++ ) {
        path += s[i];
        dfs(s, i+1);
        path.clear();
    }
    path.clear();
}

int uniqueLetterString(string & s) {
    // 回溯 + 哈希
    dfs(s, 0);

    for (int i = 0; i < res.size(); i ++ ) cout << res[i] << endl;

    int ans = 0;
    for (int i = 0; i < res.size(); i ++ ) {
        for (int j = 0; j < res[i].size(); j ++ ) {
            mp[res[i][j]] ++ ;
        }
        for (int j = 0; j < res[i].size(); j ++ ) {
            if (mp[res[i][j]] == 1) ans ++ ;
        }
        mp.clear();
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    int ans = uniqueLetterString(s);
    cout << ans << endl;
    return 0;
}