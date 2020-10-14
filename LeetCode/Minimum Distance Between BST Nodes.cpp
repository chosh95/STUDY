#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int answer = 987654321;
        TreeNode* pre = NULL;
        dfs(root, pre, answer);
        return answer;
    }

    TreeNode* dfs(TreeNode* cur, TreeNode* & pre, int answer) {
        if (!cur) return;
        dfs(cur->left, pre, answer);
        if (pre) answer = min(answer, pre->val - cur->val);
        pre = cur;
        dfs(cur->right, pre, answer);
    }
};
