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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int BSZ = sqrt(n);
  int BLK = (n + BSZ - 1) / BSZ;
  vector<int> su(BLK);
  vector<int> plus(BLK);
  auto get_blk = [&](int x) { return x / BSZ; };
  for (int i = 0; i < n; ++i) {
    su[get_blk(i)] += a[i];
  }
  auto query = [&](int l, int r) {
    int lk = get_blk(l), rk = get_blk(r);
    int res = 0;
    if (lk == rk) {
      for (int i = l; i <= r; ++i) {
        res += a[i];
        res += plus[get_blk(i)];
      }
      return res;
    }
    for (int i = l; i <= (lk + 1) * BSZ - 1; ++i) {
      res += a[i];
      res += plus[get_blk(i)];
    }
    for (int i = lk + 1; i <= rk - 1; ++i) {
      res += su[i];
    }
    for (int i = rk * BSZ; i <= r; ++i) {
      res += a[i];
      res += plus[get_blk(i)];
    }
    return res;
  };
  auto add = [&](int l, int r, int x) {
    int lk = get_blk(l), rk = get_blk(r);
    if (lk == rk) {
      for (int i = l; i <= r; ++i) {
        a[i] += x;
        su[get_blk(i)] += x;
      }
      return;
    }
    for (int i = l; i <= (lk + 1) * BSZ - 1; ++i) {
      a[i] += x;
      su[get_blk(i)] += x;
    }
    for (int i = lk + 1; i <= rk - 1; ++i) {
      su[i] += x * BSZ;
      plus[i] += x;
    }
    for (int i = rk * BSZ; i <= r; ++i) {
      a[i] += x;
      su[get_blk(i)] += x;
    }
  };
  for (int i = 1; i <= n; ++i) {
    int opt, l, r, c;
    cin >> opt >> l >> r >> c;
    if (opt == 0) {
      add(l - 1, r - 1, c);
    } else {
      cout << query(l - 1, r - 1) % (c + 1) << endl;
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
