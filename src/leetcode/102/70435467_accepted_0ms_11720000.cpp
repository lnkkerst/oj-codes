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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int> >(0);
        vector<vector<int> > ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            for(int i = 0; i < sz; ++i) {
                auto k = q.front();
                q.pop();
                tmp.push_back(k->val);
                if(k->left) q.push(k->left);
                if(k->right) q.push(k->right);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};