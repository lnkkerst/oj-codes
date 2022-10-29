/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ret;
    if (!root)
      return ret;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      ret.push_back(q.front()->val);
      for (int i = 1; i <= sz; ++i) {
        auto u = q.front();
        q.pop();
        if (u->right)
          q.push(u->right);
        if (u->left)
          q.push(u->left);
      }
    }
    return ret;
  }
};