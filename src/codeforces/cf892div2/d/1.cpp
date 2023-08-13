#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
  int l, r, a, b;
  bool operator<(const Node &b) {
    if (this->l == b.l) {
      return this->b < b.b;
    }
    return this->l < b.l;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<Node> a(n);
  for (auto &i : a) {
    cin >> i.l >> i.r >> i.a >> i.b;
  }
  sort(a.begin(), a.end());
  vector<pair<int, int>> b;
  int cl = a.front().l, cr = a.front().b;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i].l <= cr) {
      cr = max(cr, a[i].b);
    } else {
      b.emplace_back(cl, cr);
      cl = a[i].l;
      cr = a[i].b;
    }
  }
  b.emplace_back(cl, cr);
  // for (auto i : b) {
  //   cout << i.first << ' ' << i.second << endl;
  // }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    auto it = upper_bound(b.begin(), b.end(), make_pair(x, int(2e9)));
    if (it == b.begin()) {
      cout << x << ' ';
      continue;
    }
    --it;
    cout << max(x, it->second) << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
