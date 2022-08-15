#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

const int N = 13;

int n, a[N];
vector<vector<int>> res;
vector<int> path;

inline void backtrack(int a[], int start)
{
    res.push_back(path);
    for (int i = start; i < n; i ++ )
    {
        path.push_back(a[i]);  // select
        backtrack(a, i + 1);
        path.pop_back();
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    backtrack(a, 0);

    for (int i = 0; i < res.size(); i ++ )
    {
        for (int j = 0; j < res[i].size(); j ++ )
            cout << res[i][j] << ' ';
        cout << endl;
    }

    return 0;
}