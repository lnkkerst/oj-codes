class Solution {
public:
  const int dx[4], dy[4];
  Solution(): dx{0, 1, 0, -1}, dy{-1, 0, 1, 0} {};
  void dfs(vector<vector<int>> &a, int x, int y, int &ans, int now) {
    if (now >= ans) {
      return;
    }
    if (x == a.size() || x == -1 || y == -1 || y == a[0].size()) {
      return;
    }
    if (a[x][y] == 0) {
      ans = min(ans, now);
      return;
    }
    for (int i = 0; i < 4; ++i) {
      dfs(a, x + dx[i], y + dy[i], ans, now + 1);
    }
  }
  vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    auto ret = matrix;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        int ans = 1e9;
        dfs(matrix, i, j, ans, 0);
        ret[i][j] = ans;
      }
    }
    return ret;
  }
};
