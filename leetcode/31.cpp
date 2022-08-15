#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

inline void rev(vector<int> &nums, int i, int j) {
    int tp = nums[i];
    nums[i] = nums[j];
    nums[j] = tp;
}

int main() {
    int len;
    scanf("%d", &len);
    vector<int> nums;
    for (int i = 0; i < len; i++) {
        int x;
        scanf("%d", &x);
        nums.push_back(x);
    }

    int n = nums.size();
    int tpa, tpb;
    int i;
    for (i = n - 1; i > 0; i--) {
        if (nums[i - 1] >= nums[i]) continue;
        tpa = i - 1;
        for (int j = n - 1; j > tpa; j--) {
            if (nums[tpa] >= nums[j]) continue;
            tpb = j;
            break;
        }
        break;
    }
    if (i == 0) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            cout << nums[i] << ' ';
        }
        return 0;
    }
    cout << tpa << ' ' << tpb << endl;
    rev(nums, tpa, tpb);
    sort(nums.begin() + tpa + 1, nums.end(), less<int>());

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}