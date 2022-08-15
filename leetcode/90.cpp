#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> path;

inline void backtrack(vector<int> nums, int start)
{
    res.push_back(path);
    unordered_set<int> uset;
    for (int i = start; i < nums.size(); i ++ )
    {
        if (uset.find(nums[i]) != uset.end()) continue;
        uset.emplace(nums[i]);
        path.push_back(nums[i]);
        backtrack(nums, i + 1);
        path.pop_back();
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int & i : nums) scanf("%d", &i);

    sort(nums.begin(), nums.end());
    backtrack(nums, 0);
    for (int i = 0; i < res.size(); i ++ )
    {
        for (int j = 0; j < res[i].size(); j ++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}