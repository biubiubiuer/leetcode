#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 17, M = 89;
int T;
char s[N];
int mp[M];

inline void init() {
    mp['3'] = 1, mp['4'] = 2, mp['5'] = 3, mp['6'] = 4,
    mp['7'] = 5, mp['8'] = 6, mp['9'] = 7, mp['T'] = 8,
    mp['J'] = 9, mp['Q'] = 10, mp['K'] = 11,
    mp['A'] = 12, mp['2'] = 13,
    mp['X'] = 14, mp['D'] = 15;
}

inline bool cmp(char c, char d) {
    return mp[c] > mp[d];
}

int main() {
    init();

    cin >> T;
    while (T -- ) {
        scanf("%s", s);
        sort(s, s + 17, cmp);

        int j = 0;
        for (; j < 17; j++) {
            if (j >= 1 && s[j] == 'X' && s[j - 1] == 'D') {
                puts("Yes");
                break;
            }
            if (j >= 3 && s[j] == s[j - 1] && s[j] == s[j - 2] && s[j] == s[j - 3]) {
                puts("Yes");
                break;
            }
        }

        if (j == 17) puts("No");

        memset(s, 0, sizeof s);
    }

    return 0;
}
