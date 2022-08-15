/*
小红有一棵个节点的二叉树，节点的编号为，且每个节点的初始权值都为0。
对于这棵二叉树小红会进行k次操作，每次操作小红会选择一个节点编号id，让以该编号节点为根的子树上节点的权值都异或上v。
小红现在给你这棵树的结构以及每次操作的情况，小红想知道在她进行k次操作之后该棵二叉树各个节点的权值情况是多少呢，请你返回该树的权值情况。
你需要完善一个函数，函数的第一个参数为给定的树的编号情况，第二个参数代表小红的操作，每个操作的第一项为编号id，第二项为异或的值v。

 {1,2,3},[[2,4],[1,2]]
 {2,6,2}

 {2,1,3,#,4},[[3,2],[1,4],[1,3],[4,2],[2,1]]
 {1,6,3,#,4}

 https://www.nowcoder.com/question/next?pid=39959332&qid=2589596&tid=58275618
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

inline TreeNode *xorTree(TreeNode *root, vector<vector<int>> &op) {
    vector<TreeNode *> t_nodes;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        t_nodes.push_back(t);
        if (t->left != nullptr) {
            q.push(t->left);
        }
        if (t->right != nullptr) {
            q.push(t->right);
        }
    }

    for (int i = 0; i < op.size(); i++) {
        t_nodes[op[i][0]]->val ^= op[i][1];
    }

    return root;
}

int main() {
    int node_num;
    scanf("%d", &node_num);
    vector<int> nodes;
    for (int i = 0; i < node_num; i++) {
        int val;
        scanf("%d", &val);
        nodes.push_back(val);
    }
    int idx = 0;
    TreeNode *node = new TreeNode(nodes[idx]);
    queue<TreeNode *> q;
    q.push(node);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (++idx < node_num && nodes[idx] != '#') {
            q.push(new TreeNode(nodes[idx]));
            t->left = q.back();
        }
        if (++idx < node_num && nodes[idx] != '#') {
            q.push(new TreeNode(nodes[idx]));
            t->right = q.back();
        }
    } // end build tree


    int op_num;
    scanf("%d", &op_num);
    vector<vector<int>> op(op_num);
    for (int i = 0; i < op_num; i++) {
        int w, v;
        scanf("%d%d", &w, &v);
        op[i].push_back(w);
        op[i].push_back(v);
    }

    TreeNode *dummy = xorTree(node, op);

    // output here
    q.push(dummy);
    cout << dummy->val << ' ';
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (t->left != nullptr) {
            q.push(t->left);
            cout << t->left->val << ' ';
        }
        if (t->right != nullptr) {
            q.push(t->right);
            cout << t->right->val << ' ';
        }
    }
}