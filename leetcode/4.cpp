#include <iostream>
#include <vector>

using namespace std;

int findKthNumber(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if (nums1.size() - i > nums2.size() - j) {
        return findKthNumber(nums2, j, nums1, i, k);
    }

    if (nums1.size() == i) return nums2[j + k - 1];
    if (k == 1) return min(nums1[i], nums2[j]);

    int si = min(i + (k >> 1), int(nums1.size())), sj = j + (k >> 1);
    if (nums1[si - 1] > nums2[sj - 1]) {
        return findKthNumber(nums1, i, nums2, j + (k >> 1), k - (k >> 1));
    }
    else {
        return findKthNumber(nums1, si, nums2, j, k - (si - i));
    }
}

double findMethodSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    if (!(total & 1)) {
        int left = findKthNumber(nums1, 0, nums2, 0, total >> 1);
        int right = findKthNumber(nums1, 0, nums2, 0, (total >> 1) + 1);
        return (left + right) / 2.0;
    }

    else {
        return findKthNumber(nums1, 0, nums2, 0, (total >> 1) + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  
    int n, m, x;
    cin >> n >> m;
    vector<int> nums1, nums2;
    for (int i = 0; i < n; i ++ ) {
        cin >> x;
        nums1.push_back(x);
    }
    for (int i = 0; i < m; i ++ ) {
        cin >> x;
        nums2.push_back(x);
    }

    double res;
    res = findMethodSortedArrays(nums1, nums2);

    cout << "res: " << res << endl;
  
    return 0;
}
