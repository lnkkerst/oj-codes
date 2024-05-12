#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Tree {
  vector<int> a;
  int n;
  Tree(int _n) : n(_n), a(_n + 10) {
  }
  static int lowbit(int x) {
    return x & -x;
  }
  void add(int k, int x) {
    while (k <= n) {
      a[k] += x;
      k += lowbit(k);
    }
  }
  int query(int k) {
    int res = 0;
    while (k) {
      res += a[k];
      k -= lowbit(k);
    }
    return res;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  set<int> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b.insert(a[i]);
  }
  if (b.size() != n) {
    cout << "Karashi lovelove" << endl;
    return;
  }
  auto calc = [&](const vector<int> &a) {
    vector<vector<pair<int, int>>> bk;
    vector<int> p;

    bk.push_back({{-1, a[0]}});
    p.push_back(a[0]);

    auto push = [&](int k, int num) {
      int j = (k == 0) ? -1 : (bk[k - 1].size() - 1);
      bk[k].push_back({j, num});
      p[k] = num;
    };

    for (int i = 1; i < a.size(); i++) {
      if (a[i] > p[p.size() - 1]) {
        bk.push_back({});
        p.push_back(0);
        push(bk.size() - 1, a[i]);
      } else {
        int k = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
        push(k, a[i]);
      }
    }

    vector<int> ans(bk.size());

    for (int i = bk.size() - 1, j = -1; i >= 0; i--) {
      auto &b = bk[i];
      auto &[j1, num] = b[j < 0 ? (b.size() - 1) : j];
      j = j1;
      ans[i] = num;
    }

    return ans;
  };

  int cnt = 0;
  while (!a.empty()) {
    auto lis = calc(a);
    vector<int> na;
    set<int> b;
    for (auto i : lis) {
      b.insert(i);
    }
    for (auto i : a) {
      if (b.find(i) == b.end()) {
        na.emplace_back(i);
      }
    }
    a = na;
    ++cnt;
  }
  if (cnt > m) {
    cout << "Karashi lovelove" << endl;
  } else {
    cout << "Karashi cblcd" << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
