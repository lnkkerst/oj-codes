class Solution {
public:
  bool b[55];
  int aa[10000];
  void dfs(vector<vector<int>> &a, int pos, int &ret) {
    if (pos == a.size()) {
      ++ret;
      ret %= (int)1e9 + 7;
      return;
    }
    for (auto i : a[pos]) {
      if (!b[i]) {
        b[i] = 1;
        aa[pos] = i;
        dfs(a, pos + 1, ret);
        b[i] = 0;
      }
    }
  }
  int numberWays(vector<vector<int>> &hats) {
    int ret = 0;
    dfs(hats, 0, ret);
    return ret;
  }
};
