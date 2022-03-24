class Solution {
public:
	const int dx[4], dy[4];
	Solution() : dx{0, 1, 0, -1}, dy{-1, 0, 1, 0}{}
	void dfs(vector<vector<int> > &a, vector<vector<int> > &b, int x, int y, int &ans, int dep) {
        if(dep >= 1000) return ;
		if(x < 0 || y < 0 || x >= (int)a.size() || y >= (int)a[0].size()) return ;
		if(b[x][y] || dep >= ans) return ;
		if(!a[x][y]) {
			ans = min(ans, dep);
			return ;
		}
		b[x][y] = 1;
		for(int i = 0; i < 4; ++i)
			dfs(a, b, x + dx[i], y + dy[i], ans, dep + 1);
		b[x][y] = 0;
		return ;
	}
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
		vector<vector<int> > ret(a.size()), b(a.size());
		for(auto &i : ret) i.resize(a[0].size());
		for(auto &i : b) i.resize(a[0].size());
		for(int i = 0; i < (int)a.size(); ++i)
			for(int j = 0; j < (int)a[0].size(); ++j)
				if(a[i][j]) {
					ret[i][j] = 0x7fffffff;
					dfs(a, b, i, j, ret[i][j], 0);
				}
				else ret[i][j] = 0;
		return ret;
    }
};