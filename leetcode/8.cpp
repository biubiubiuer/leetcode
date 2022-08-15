#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

typedef long long ll;

string s;

int main() {
    scanf("%s", &s);
    int n = s.size();
    bool is_pos = true;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') continue;
        else if (s[i] == '+') is_pos = true;
        else if (s[i] == '-') is_pos = false;
        else {
            for (int j = i; j < n; j++) {
                if (s[j] < '1' || s[j] > '9') break;
                else if (s[j] == '+') is_pos = true;
                else if (s[j] == '-') is_pos = false;
                else {
                    res = res * 10 + s[j] - '0';
                }
            }
            break;
        }
    }
    if (res > INT32_MAX) cout << INT32_MAX << endl;
    else if (res < INT32_MIN) cout << INT32_MIN << endl;
    else {
        int ans = is_pos ? res : -1 * res;
        cout << ans << endl;
    }
    return 0;
}