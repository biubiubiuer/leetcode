#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

inline int s2i(string &s, int k) {
    int n = s.size();
    int l = n - k;
    int x = 0;
    for (int i = l; i < n; i ++ ) {
        x *= 10;
        x += s[i] - '0';
    }
    cout << x << endl;
    return x;
}
    
vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
    int n = nums.size(), m = q.size();
    vector<int> ans(m);
    
    for (int i = 0; i < m; i ++ ) {
        int k = q[i][0], t = q[i][1];
        vector<int> tmp(n);
        for (int j = 0; j < n; j ++ ) {
            int x = s2i(nums[j], k);  // 返回后k位的整数
            tmp[j] = x;
        }
        // 找到第k小
        sort(tmp.begin(), tmp.end());
        int idx = k - 1;
        for (; idx >= 1; idx -- ) {
            if (tmp[idx] != tmp[idx - 1]) break;
        }
        ans[i] = idx;
        
        cout << "----------" << endl;
    }
    
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> nums(n);
    vector<vector<int>> q(m, vector<int>(2));
    for (int i = 0; i< n; i ++ ) {
        cin >> nums[i];
    }
    for (int i = 0; i < m; i ++ ) {
        cin >> q[i][0] >> q[i][1];
    }

    vector<int> ans = smallestTrimmedNumbers(nums, q);
    for (int i = 0; i < ans.size(); i ++ ) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}