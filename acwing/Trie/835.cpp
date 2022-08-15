#include <iostream>
#include <string>
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 100010;
// son[i]表示下标为i的节点的所有儿子。
// 树根默认是0，此外，它也表示空节点
int son[N][26], cnt[N], idx;

inline void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        // 先++，再赋值，因为idx一开始是0，而0是树根占的位置
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++;
}

inline int query(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main() {
    ios
    int n;
    cin >> n;
    while (n--) {
        char op;
        string s;
        cin >> op;
        cin >> s;

        if (op == 'I') insert(s);
        else if (op == 'Q') cout << query(s) << endl;
    }

    return 0;
}
