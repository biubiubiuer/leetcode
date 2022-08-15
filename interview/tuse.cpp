#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
char s[N];
int n;
int main() {
    cin >> n;
    scanf("%s", s);
    n = strlen(s);
    char l = s[0], r = s[n-1];
    if (l == r) // case 两端同色
    {
        int minv = N;
        int v1 = 0, v2 = 2;
        // case 1.1: all red
        // case 1.2: all blue
        // case 1.3: red to blue
        // case 1.4: blue to red
        for (int i = 0; i < n; i ++ ) {
            if (s[i] != l) v1 ++ ;
            else v2 ++ ;

        }
        minv = min(v1, v2);
        int v3 = 1, v4 = 1;
        int lr, rl;
        for (int i = 1; i < n - 1; i ++ ) {
            if (s[i] != r) {
                lr = i;
                break;
            }
        }
        for (int i = n - 1; i >= 1; i -- ) {
            if (s[i] == l) {
                rl = i;
                break;
            }
        }
        for (int i = 1; i < rl; i ++ ) {
            if (s[i] != l) v3 ++ ;
        }
        for (int i = n - 1; i > lr; i -- ) {
            if (s[i] == r) v4 ++ ;
        }
        minv = min(minv, min(v3, v4));
        int v5 = 1, v6 = 1;
        for (int i = 1; i < n - 1; i ++ ) {
            if (s[i] == r) {
                lr = i;
                break;
            }
        }
        for (int i = n - 1; i >= 1; i -- ) {
            if (s[i] != l) {
                rl = i;
                break;
            }
        }
        for (int i = 1; i < rl; i ++ ) {
            if (s[i] == l) v5 ++ ;
        }
        for (int i = n - 1; i > lr; i -- ) {
            if (s[i] != r) v6 ++ ;
        } 
        minv = min(minv, min(v5, v6));
        cout << minv << endl;
        return 0;
    }
    else // case 2 两端异色
    {
        int minv = N;
        int v1 = 0, v2 = 0;
        // case 1.1: all red
        // case 1.2: all blue
        // case 1.3: red to blue
        // case 1.4: blue to red
        for (int i = 0; i < n; i ++ ) {
            if (s[i] != l) v1 ++ ;
            else v2 ++ ;
        }
        minv = min(v1, v2);
        int v3 = 0, v4 = 0;
        int lr, rl;
        for (int i = 1; i < n - 1; i ++ ) {
            if (s[i] == r) {
                lr = i;
                break;
            }
        }
        for (int i = n - 1; i >= 1; i -- ) {
            if (s[i] == l) {
                rl = i;
                break;
            }
        }
        for (int i = 1; i < rl; i ++ ) {
            if (s[i] != l) v3 ++ ;
        }
        for (int i = n - 1; i > lr; i -- ) {
            if (s[i] != r) v4 ++ ;
        }
        minv = min(minv, min(v3, v4));
        int v5 = 2, v6 = 2;
        char c = l, l = r, r = c;
        for (int i = 1; i < n - 1; i ++ ) {
            if (s[i] == r) {
                lr = i;
                break;
            }
        }
        for (int i = n - 1; i >= 1; i -- ) {
            if (s[i] == l) {
                rl = i;
                break;
            }
        }
        for (int i = 1; i < rl; i ++ ) {
            if (s[i] != l) v5 ++ ;
        }
        for (int i = n - 1; i > lr; i -- ) {
            if (s[i] != r) v6 ++ ;
        } 
        minv = min(minv, min(v5, v6));
        cout << minv << endl;
        return 0;
    }
}