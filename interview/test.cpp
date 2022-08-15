#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
const int maxn = 1005;
int a[maxn];
int n;
unordered_map<int, int> mp;
vector<int> res;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        a[i] = rand() % 500;
        cout << a[i] << " ";
        if (++ mp[a[i]] > 1) continue;
        res.push_back(a[i]);
    }
    cout << endl;
    cout << "----------" << endl;
    
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i ++ ) cout << res[i] << ' ';
    cout << endl; 
    cout << res.size() << endl;
    
    return 0;
}