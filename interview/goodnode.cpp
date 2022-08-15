/*
现在给你一棵树, 每个树上的节点会被涂成黑色 1 或白色 0
现在定义好节点:
对于白色的节点: 若该节点没有子节点, 或该节点子节点中至少有一个为黑色节点, 则该节点是好节点
对于黑色的节点: 若该节点没有子节点, 或该节点的所有子节点均为白色节点, 则该节点是好节点
你的任务是找出这棵树上黑色的好节点和白色的好节点各有几个
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10005;

int n, rt, col[N], ans[2];
vector<int> edge[N];

void dfs(int x)
{
    if (edge[x].size() == 0)
    {
        ans[col[x]] ++ ;
        return ;
    }
    int b = 0;
    for (auto v : edge[x])
    {
        dfs(v);
        if (col[v] == 1) b ++ ;
    }
    if (col[x] == 0 && b > 0) ans[col[x]] ++ ;
    else if (col[x] == 1 && b == 0) ans[col[x]] ++ ;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> col[i];
    for (int i = 1, fa; i <= n; i ++ )
    {
        cin >> fa;
        if (fa == 0) rt = i;
        else edge[fa].push_back(i);
    }
    dfs(rt);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}