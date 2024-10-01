class Solution {
public:
  void dfs(vector<int> &a, int now, int dep, vector<int> &b, int &ans) {
    if (now >= (int)b.size() - 1) {
      ans = min(dep, ans);
      return;
    }
    // cout << now << ' ' << dep << ' ' << now + b[now] << endl;
    if (dep > a[now]) {
      return;
    }
    a[now] = min(a[now], dep);
    dfs(a, now + b[now], dep + 1, b, ans);
    if (now > 0) {
      dfs(a, now - 1, dep + 1, b, ans);
    }
  }
  int minJump(vector<int> &jump) {
    int ret = 0x7fffffff;
    vector<int> a(jump.size(), 0x7fffffff);
    dfs(a, 0, 0, jump, ret);
    return ret;
  }
};
