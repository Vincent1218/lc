// 199. Binary Tree Right Side View

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int depth, vector<int> &ans) {
      if (!root) return;
      if (ans.size() == depth) ans.push_back(root->val);
      dfs(root->right, depth + 1, ans);
      dfs(root->left, depth + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      dfs(root, 0, ans);
      return ans;   
    }
};