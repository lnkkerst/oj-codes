class Solution {
public:
    void dfs(int n, vector<vector<int>>& a, int now, int dep, int k, int &ans) {
        if(dep == k) {
            if(now == n - 1) ++ans;
            return ;
        }
        for(auto i : a[now]) {
            dfs(n, a, i, dep + 1, k, ans);
        }
    }
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int ret = 0;
        vector<vector<int> > a(n);
        for(auto i : relation) {
            a[i[0]].push_back(i[1]);
        }
        dfs(n, a, 0, 0, k, ret);
        return ret;
    }
};