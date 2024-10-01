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

#define endl '\n'

struct Tree {
  vector<int> a;
  int n;
  Tree(int _n): n(_n), a(_n + 10) {}
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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  string rs = "PQYSZTMNB";
  vector<map<char, int>> last(n + 1);
  for (int i = 1; i <= n; ++i) {
    last[i] = last[i - 1];
    last[i][s[i - 1]] = i - 1;
  }
  while (q--) {
    string x;
    cin >> x;
    map<char, bool> b;
    for (auto c : x) {
      b[c] = 1;
    }
    int ans = 0;
    int l = 1;
    int cnt = 0;
    map<int, int> cur;
    for (int r = 1; r <= n; ++r) {
      auto c = s[r];
      if (b[c]) {
        ++cur[c];
        while (cur[c] > 1) {
          if (b[s[l]]) {
            --cur[s[l]];
            if (cur[s[l]] == 0) {
              cur.erase(s[l]);
            }
          }
          ++l;
        }
      }
      if (cur.size() == x.size()) {
        ans = max(ans, r - l + 1);
      }
    }
    cout << ans << endl;
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
