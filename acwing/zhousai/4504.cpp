#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 1e5 + 10;
char s[N];
unordered_map<char, int> mp;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    bool is_hua = true;
    bool is_seq = false;
    mp[s[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) is_seq = true;

        if (mp[s[i]] == i - 1) {
            remove(&s[i]), remove(&s[i]);
            n -= 2;
            i -= 2;
            is_hua = !is_hua;
        } else mp[s[i]] = i;
    }
    if (!is_seq) {
        puts("No");
        return 0;
    }
    if (is_hua) puts("No");
    else puts("Yes");

    return 0;
}