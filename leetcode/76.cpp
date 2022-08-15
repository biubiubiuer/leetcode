#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    if (s.size() < t.size()) return 0;

    unordered_map<char, int> hs, ht;

    for (char & c : t)
        ht[c] ++ ;

    string res;

    int l = 0, r = 0;
    int cnt = 0;

    while (r < s.size()) {
        hs[s[r]] ++ ;
        if (hs[s[r]] <= ht[s[r]])
            cnt += 1;
        while (l <= r && hs[s[l]] < ht[s[l]])
            hs[s[l++]] --;
        if (cnt == t.size())
            if (res.empty() || r - l + 1 < res.size())
                res = s.substr(l, r - l + 1);
        r ++ ;
    }

    cout << res << endl;

    return 0;
}