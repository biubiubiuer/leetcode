#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

TreeNode* addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
        TreeNode *ans(val);
        ans->left = root;
        return ans;
    }
    deque<TreeNode *> d;
    int cur = 1;
    while (!d.empty()) {
        int n = d.size();
        for (int i = 0; i < n; ++i) {
            auto t = d.front();
            if (cur == depth - 1) {
                TreeNode *a(val), *b(val);
                a->left = t->left, b->right = t->right;
                t->left = a, t->right = b;
            } else {
                if (t->left) d.push_back(t->left);
                if (t->right) d.push_back(t->right);
            }
        }
        cur ++ ;
    }
    return root;
}  