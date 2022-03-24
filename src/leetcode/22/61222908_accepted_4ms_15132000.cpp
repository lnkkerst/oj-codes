class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        dfs(n, n, "", ret);
        return ret;
    }
    void dfs(int l, int r, string now, vector<string> &ret) {
        if(!l && !r) {
            ret.push_back(now);
            return ;
        }
        if(l > 0) dfs(l - 1, r, now + '(', ret);
        if(r > l) dfs(l, r - 1, now + ')', ret);
        return ;
    }
};