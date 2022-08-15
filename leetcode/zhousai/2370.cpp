#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
char s[N];
int n, k;
int main() 
{
    scanf("%s", s);
    n = strlen(s);
    scanf("%d", &k);
    int f[26] = {};
    for (char c : s) 
    {
        c -= 'a';
        f[c] = 1 + *max_element(f + max(c - k, 0), f + min(c + k + 1, 26));
    }
    cout << *max_element(f, f + 26) << endl;
    return 0;
}