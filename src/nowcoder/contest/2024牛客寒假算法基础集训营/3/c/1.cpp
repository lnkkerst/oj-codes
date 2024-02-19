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

#define int long long

vector<int> z_function(const string &s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0ll, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        ++z[i];
      }
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}

auto manacher(const string &s) {
  int n = s.length();

  vector<int> d1(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }

  vector<int> d2(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }

  return make_pair(d1, d2);
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  auto calc = [&]() {
    auto zpre = z_function(s + t);
    auto mpre = manacher(s + t);
    vector<int> pre;
    // for (auto i : s + t) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    // for (auto i : zpre) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    // for (auto i : mpre.first) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    // for (auto i : mpre.second) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    int tl = n + m;
    for (int i = 1; i < tl; ++i) {
      int rsz = tl - i;
      int lsz = zpre[i];
      if (lsz != rsz) {
        continue;
      }
      if (lsz >= n || rsz >= m) {
        continue;
      }
      // cout << lsz << endl;
      if (lsz & 1) {
        int len = mpre.first[lsz / 2];
        len = len * 2 - 1;
        if (len == lsz && lsz) {
          pre.emplace_back(lsz);
        }
      } else {
        int len = mpre.second[lsz / 2];
        len = len * 2;
        if (len == lsz && lsz) {
          pre.emplace_back(lsz);
        }
      }
    }
    return pre;
  };
  auto pre = calc();
  swap(s, t);
  swap(n, m);
  auto suf = calc();
  // for (auto i : pre) {
  //   cout << i << ' ';
  // }
  // cout << endl;
  // for (auto i : suf) {
  //   cout << i << ' ';
  // }
  // cout << endl;
  int mn = min(n, m);
  sort(pre.begin(), pre.end());
  sort(suf.begin(), suf.end());
  int ans = -1;
  for (auto x : pre) {
    int top = mn - x;
    auto it = upper_bound(suf.begin(), suf.end(), top);
    if (it == suf.begin()) {
      continue;
    }
    --it;
    ans = max(ans, *it + x);
  }
  if (ans == -1) {
    cout << -1 << endl;
    return;
  }
  cout << ans * 2 << endl;
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
