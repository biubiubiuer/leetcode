/*
给定一棵树，每一个节点有一个权重，选择其中某些节点，满足被选中的节点两两不相邻，
求在所有的选择方案中，最大化被选择节点权值之和的情况下，被选择节点权值最小值尽可能大。
(白话一点说就是，优先保证选择的节点权值和最大；如果有多个和最大的情况，要优先选择选中的节点中最小的值是最大的。
比如和最大是 10，你可以选择 1 9，也可以选择 2 8，这种时候要优先选择 2 8，因为 2 要比 1 大)。

树是一种无向联通图，任意节点两两可达且无环。

输入
第一行两个整数 N 和 M，分别表示树的节点数和边数\

第二行为 N 个整数，分别表示每个节点的权重\

接下来 M 行，每行两个整数 a 和 b，存在一条从 a 到 b 的边。

输出
输出两个整数，表示能选择的最大权值之和是多少，以及权值最小值是多少，用空格分割。

输入样例
5 4
3 4 1 4 9
1 2
1 3
2 4
3 5

输出样例
16 3
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

unsigned main()
{
    return 0;
}