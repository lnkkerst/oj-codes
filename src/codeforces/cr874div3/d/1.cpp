#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ma = max_element(a.begin(), a.end()) - a.begin();
  int r = ma - 1;
  vector<int> ans;
  auto calc = [&](int l, int r) {
    vector<int> res;
    for (int i = r + 1; i < a.size(); ++i) {
      res.emplace_back(a[i]);
    }
    for (int i = r; i >= l; --i) {
      res.emplace_back(a[i]);
    }
    for (int i = 0; i < l; ++i) {
      res.emplace_back(a[i]);
    }
    return res;
  };
  for (int l = r; l >= 0; --l) {
    auto t = calc(l, r);
    if (ans.empty()) {
      ans = t;
    } else if (t > ans) {
      ans = t;
    }
  }
  auto t = calc(ma, ma);
  if (ans.empty()) {
    ans = t;
  } else if (t > ans) {
    ans = t;
  }
  int ma2 = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (i == ma) {
      continue;
    }
    if (ma2 == -1) {
      ma2 = i;
    } else if (a[i] > a[ma2] && i != ma) {
      ma2 = i;
    }
  }
  // cout << ma2 << endl;
  r = ma2 - 1;
  for (int l = r; l >= 0; --l) {
    auto t = calc(l, r);
    if (ans.empty()) {
      ans = t;
    } else if (t > ans) {
      ans = t;
    }
  }
  for (int i = 0; i < n; ++i) {
    t = calc(i, i);
    if (ans.empty()) {
      ans = t;
    } else if (t > ans) {
      ans = t;
    }
  }
  for (auto i : ans) {
    cout << i << ' ';
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
