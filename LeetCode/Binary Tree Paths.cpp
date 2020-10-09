#include <iostream>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {};
        vector<string> answer; 

        queue<pair<TreeNode*, string>> q;
        q.push({ root,to_string(root->val) });

        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            string str = q.front().second;
            q.pop();

            if (cur->left == NULL && cur->right == NULL) {
                answer.push_back(str);
                continue;
            }
            if (cur->left) {
                TreeNode* left = cur->left;
                string next = str +  "->" + to_string(left->val);
                q.push({ left,next });
            }
            if (cur->right) {
                TreeNode* right= cur->right;
                string next = str + "->" + to_string(right->val);
                q.push({ right,next });
            }
        }

        return answer;
    }
};

