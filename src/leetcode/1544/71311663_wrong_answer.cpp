/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  void dfs(TreeNode *u, int &ans, int last) {
    // cout << u->val << ' ' << last << endl;
    if (last <= u->val) {
      ++ans;
    }
    last = max(last, u->val);
    if (u->left) {
      dfs(u->left, ans, last);
    }
    if (u->right) {
      dfs(u->right, ans, last);
    }
  }
  int goodNodes(TreeNode *root) {
    int ans = 0;
    dfs(root, ans, -1);
    return ans;
  }
};
