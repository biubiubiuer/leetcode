#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 400005;

string s;
string qc;
vector<int> qi;

int L[N], R[N], All[N];

inline void merge(int node, int l, int r) {
    int nl = node << 1, nr = nl | 1, m = l + r >> 1;
    All[node] = max(All[nl], All[nr]);
    L[node] = L[nl];
    R[node] = R[nr];
    if (s[m] == s[m + 1]) {
        All[node] = max(All[node], R[nl] + L[nr]);
        if (All[nl] == m - l + 1) {
            L[node] += L[nr];
        }
        if (All[nr] == r - m) {
            R[node] += R[nl];
        }
    }
}

inline void build(int node, int l, int r) {
    if (l == r) {
        L[node] = R[node] = All[node] = 1;
    } else {
        int m = l + r >> 1;
        build(node << 1, l, m);
        build((node << 1) | 1, m + 1, r);
        merge(node, l, r);
    }
}

inline int query(int node, int l, int r, int i, char c) {
    if (l == r) {
        s[l] = c;
    } else {
        int m = l + r >> 1;
        if (i <= m) query(node << 1, l, m, i, c);
        else query((node << 1) | 1, m + 1, r, i, c);
        merge(node, l, r);
    }
    return All[node];
}

inline vector<int> longestRepeating(string s, string qc, vector<int> &qi) {

    build(1, 0, s.size() - 1);

    vector<int> res;
    for (int i = 0; i < qc.size(); i++) {
        res.push_back(query(1, 0, s.size() - 1, qi[i], qc[i]));
    }
    return res;
}

int main() {

    getline(cin, s);
    getline(cin, qc);
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        qi.push_back(x);
    }

    vector<int> res;
    res = longestRepeating(s, qc, qi);

    for (int &r: res) cout << r << ' ';
    cout << endl;

    return 0;
}