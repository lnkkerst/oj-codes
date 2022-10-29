class Solution {
public:
  vector<vector<string>> ret;
  int x[233], n, ans = 0;
  bool y[233], dx[233], dy[233];
  void dfs(int step) {
    if (step > n) {
      ++ans;
      vector<string> tmp;
      for (int i = 1; i <= n; ++i) {
        string ll;
        ll.resize(n);
        fill(ll.begin(), ll.end(), '.');
        ll[x[i] - 1] = 'Q';
        tmp.push_back(ll);
      }
      ret.push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
      if (!y[i] && !dx[i + step] && !dy[step - i + n]) {
        x[step] = i;
        y[i] = 1;
        dx[i + step] = 1;
        dy[step - i + n] = 1;
        dfs(step + 1);
        y[i] = 0;
        dx[i + step] = 0;
        dy[step - i + n] = 0;
      }
    }
  }
  vector<vector<string>> solveNQueens(int nn) {
    n = nn;
    dfs(1);
    return ret;
  }
};
