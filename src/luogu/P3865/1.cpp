#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(21, -1));
  vector<int> l2(1e6);
  int base = 2;
  for (int i = 2; i < 1e6; ++i) {
    if (i == base) {
      l2[i] = l2[i - 1] + 1;
      base *= 2;
    } else {
      l2[i] = l2[i - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0];
  }
  function<int(int, int)> dfs = [&](int i, int j) -> int {
    if (a[i][j] != -1) {
      return a[i][j];
    }
    a[i][j] = max(dfs(i, j - 1), dfs(i + 1, j));
    return a[i][j];
  };
  while (m--) {
    int l, r;
    cin >> l >> r;
    int s = l2[r - l + 1];
    cout << max(dfs(l, s), dfs(r - (1 << s) + 1, s)) << endl;
  }
}
