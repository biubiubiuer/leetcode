/*
牛牛有一棵n个节点的二叉树，该二叉树每个节点的权值为1。牛牛想要删掉该树其中的k层节点，删除序列为。
如有一棵二叉树，删除其中的第3层节点:
      1
     / \
    1   1
   / \  /
  1   1 1
 / \   \
1   1   1
 \  /
  1 1
其会变为如下四棵二叉树:
      1
     / \
    1   1

1   1   1
 \  /
  1 1
牛牛现在给你初始二叉树，以及表示删除第几层的删除序列a。牛牛希望能能将最后剩下的子树，按照根节点层序遍历的顺序返回子树数组。

输入例子1:
{1,1,1,1,1,1,#,1,1,#,1,#,#,#,1,1},[3]

输出例子1:
[{1,1,1},{1,#,1},{1,1},{1}]

例子说明1:
其为如题意给定的二叉树所得到的子树序列。

输入例子2:
{1,#,1,#,1,#,1,#,1},[2,4]

输出例子2:
[{1},{1},{1}]

例子说明2:
给定的为一条长度为5的链，删去第2层与4层后剩下三个单节点子树。
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

inline vector<TreeNode *> deleteLevel(TreeNode *root, vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        // del layer a[i]

    }
}

int main() {
    int node_num;
    scanf("%d", &node_num);
    vector<int> node_val(node_num);
    for (int i = 0; i < node_num; i++) {
        scanf("%d", &node_val[i]);
    }

    int idx = 0;
    queue<TreeNode *> q;
    TreeNode *node = new TreeNode(node_val[idx]);
    q.push(node);
    while (q.size()) {
        auto t = q.front();
        if (++idx < node_val.size()) {
            if (node_val[idx] != '#') {
                q.push(new TreeNode(node_val[idx]));
                t->left = q.back();
            } else {
                t->left = nullptr;
            }
        }
        if (++idx < node_val.size()) {
            if (node_val[idx] != '#') {
                q.push(new TreeNode(node_val[idx]));
                t->right = q.back();
            } else {
                t->right = nullptr;
            }
        }
    } // end build tree

    int a_size;
    scanf("%d", &a_size);
    vector<int> a(a_size);
    for (int i = 0; i < a_size; i++) {
        scanf("%d", &a[i]);
    }

    vector<TreeNode *> res;
    TreeNode *dummy = node;
    res = deleteLevel(dummy, a);

    // output nodes
    for (int i = 0; i < res.size(); i++) {
        // output node.val
        q.push(res[i]);
        cout << res[i]->val << ' ';
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t->left) {
                q.push(t->left);
                cout << t->left->val << ' ';
            }
            if (t->right) {
                q.push(t->right);
                cout << t->right->val << ' ';
            }
        }
    } // end output

    return 0;

}