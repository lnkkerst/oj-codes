#pragma GCC optimize(2)
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int x, y;
  int id;
  int clr;
  bool operator<(const Node &b) const {
    if (x == b.x) {
      return y < b.y;
    }
    return x < b.x;
  }
};

void solve() {
  int n1, n2;
  cin >> n1 >> n2;
  vector<Node> a1(n1), a2(n2);
  vector<Node> a;
  for (int i = 0; i < n1; ++i) {
    cin >> a1[i].x >> a1[i].y;
    a1[i].id = i;
    a1[i].clr = 0;
  }
  for (int i = 0; i < n2; ++i) {
    cin >> a2[i].x >> a2[i].y;
    a2[i].id = i;
    a2[i].clr = 1;
  }
  for (auto i : a1) {
    a.emplace_back(i);
  }
  for (auto i : a2) {
    a.emplace_back(i);
  }
  sort(a.begin(), a.end());
  vector<int> ans[2];
  ans[0].resize(n1);
  ans[1].resize(n2);
  for (int i = 1; i < a.size(); ++i) {
    if (a[i].x != a[i - 1].x) {
      continue;
    }
    if (a[i].clr != a[i - 1].clr) {
      ans[a[i].clr][a[i].id] = 1;
      ans[a[i - 1].clr][a[i - 1].id] = 1;
    }
  }
  sort(a.begin(), a.end(), [&](const Node &a, const Node &b) {
    if (a.y == b.y) {
      return a.x < b.x;
    }
    return a.y < b.y;
  });
  for (int i = 1; i < a.size(); ++i) {
    if (a[i].y != a[i - 1].y) {
      continue;
    }
    if (a[i].clr != a[i - 1].clr) {
      ans[a[i].clr][a[i].id] = 1;
      ans[a[i - 1].clr][a[i - 1].id] = 1;
    }
  }
  for (int i = 0; i < n1; ++i) {
    cout << ans[0][i];
  }
  cout << endl;
  for (int i = 0; i < n2; ++i) {
    cout << ans[1][i];
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
