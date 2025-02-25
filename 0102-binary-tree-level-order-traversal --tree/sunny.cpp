#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return vector<vector<int>>{};
    auto q = queue<TreeNode *>{};
    auto res = vector<vector<int>>{};
    res.emplace_back(root->val);
    q.push(root);
    while (!q.empty()) {
        auto t = q.front();
        printf("the top is: %d\n", t->val);
        q.pop();
        auto curr = vector<int>{};

        auto handle = [&q, &curr](TreeNode *node) {
            if (node == nullptr) return;
            printf("handling: %d\n", node->val);
            curr.push_back(node->val);
            q.push(node);
        };
        handle(t->left);
        handle(t->right);
    }
    return res;
}

auto main() -> int {
    auto fifteen = TreeNode{15, nullptr, nullptr};
    auto seven = TreeNode{7, nullptr, nullptr};

    auto twenty = TreeNode{20, &fifteen, &seven};

    auto nine = TreeNode{9, nullptr, nullptr};

    auto three = TreeNode{3, &nine, &twenty};

    auto res = levelOrder(&three);

    for (auto r : res) {
        for (auto ri : r) cout << ri << ' ';
        cout << '\n';
    }
}
