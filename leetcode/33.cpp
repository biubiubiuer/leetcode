#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int len, target;
    scanf("%d%d", &len, &target);
    vector<int> nums(len);
    for (int i = 0; i < len; i ++ ) scanf("%d", &nums[i]);

    int l = 0, r = nums.size() - 1;
    int maxvi;
    while (l < r) {
        maxvi = l + r >> 1;
        if (nums[maxvi] >= nums[0]) {
            l = maxvi;
        }
        else if (nums[maxvi] < nums[0]) {
            r = maxvi - 1;
        }
    }

    int mid;
    l = 0, r = nums.size() - 1;
    int res;
    while (l < r) {
        mid = l + r >> 1;
        if (nums[mid] == target) res = mid;
        else if (nums[mid] < target) {
            if (mid < maxvi) {
                l = mid + 1, r = maxvi;
            }
            else {
                l = mid + 1;
            }
        }
        else {
            if (mid > maxvi) {
                l = maxvi + 1, r = mid - 1;
            }
            else {
                r = mid - 1;
            }
        }
    }

    cout << mid << endl;
    return 0;
}