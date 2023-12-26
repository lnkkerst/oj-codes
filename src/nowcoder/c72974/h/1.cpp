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

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  for (auto &i : s) {
    i -= 'a';
  }
  vector<int> tr(n + 1);
  auto add = [&](int pos, int val) {
    while (pos <= n) {
      tr[pos] += val;
      pos += pos & -pos;
    }
  };
  auto query = [&](int pos) {
    int res = 0;
    while (pos > 0) {
      res += tr[pos];
      pos -= pos & -pos;
    }
    return res;
  };
  auto query_range = [&](int l, int r) {
    return query(r) - query(l - 1);
  };
  int k = 233, p = 1e9 + 7;
  vector<int> kmi(n + 1);
  kmi[0] = 1;
  for (int i = 1; i <= n; ++i) {
    kmi[i] = kmi[i - 1] * k % p;
  }
  for (int i = 1; i <= n; ++i) {
    add(i, s[i] * kmi[n - i] % p);
  }
  auto get_hash = [&](int l, int r) {
    return (query_range(l, r) % p * kmi[l - 1] % p + p) % p;
  };
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x;
      char c;
      cin >> x >> c;
      c -= 'a';
      add(x, (c - s[x]) * kmi[n - x] % p);
      s[x] = c;
    } else {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      if (get_hash(l1, r1) == get_hash(l2, r2)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
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
