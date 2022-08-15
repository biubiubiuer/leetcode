#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        //if (nums[i] == nums[i + 1]) continue;
        int l = i + 1, r = n - 1;
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
            res.push_back({nums[i], nums[l], nums[r]});
            continue;
        } else if (sum < 0) {
            do {
                if (l + 1 < r) {
                    l++;
                    sum = nums[i] + nums[l] + nums[r];
                } else {
                    break;
                }
            } while (l < r && sum < 0);
            if (sum == 0) res.push_back({nums[i], nums[l], nums[r]});
        } else {
            do {
                if (r - 1 > l) {
                    r--;
                    sum = nums[i] + nums[l] + nums[r];
                } else {
                    break;
                }
            } while (l < r && sum > 0);
            if (sum == 0) res.push_back({nums[i], nums[l], nums[r]});
        }
    }


    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}