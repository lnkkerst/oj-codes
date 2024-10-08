class Solution {
public:
  int x[233], n, ans;
  bool y[233], dx[233], dy[233];
  void dfs(int step) {
    if (step > n) {
      ans++;
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
  int totalNQueens(int nn) {
    n = nn;
    ans = 0;
    dfs(1);
    return ans;
  }
};
