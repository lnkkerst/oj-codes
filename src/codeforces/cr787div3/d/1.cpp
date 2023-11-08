#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int fa = 0;
  int cnt = 0;
  bool vis = 0;
};

vector<Node> a;

void dfs(vector<int> &ans, int u) {
  if (u == 0) {
    return;
  }
  if (a[u].vis) {
    return;
  }
  a[u].vis = true;
  ans.emplace_back(u);
  if (a[u].fa == u) {
    return;
  }
  dfs(ans, a[u].fa);
}

void solve() {
  int n;
  cin >> n;
  a = vector<Node>(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i].fa = x;
    ++a[x].cnt;
  }
  if (n == 1) {
    cout << "1\n1\n1\n" << endl;
    return;
  }
  vector<vector<int>> ans;
  for (int i = 1; i <= n; ++i) {
    if (!a[i].cnt) {
      vector<int> tmp;
      dfs(tmp, i);
      ans.emplace_back(tmp);
    }
  }
  cout << ans.size() << endl;
  for (auto &i : ans) {
    cout << i.size() << endl;
    for (auto j = i.rbegin(); j != i.rend(); ++j) {
      cout << *j << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
