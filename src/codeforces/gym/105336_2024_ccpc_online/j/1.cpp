#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define int long long

struct XXJ {
  static constexpr int N = 60;
  bool flag = false;
  vector<int> a, tmp;

  XXJ() : a(N), tmp(N) {}

  void insert(int x) {
    for (int i = N; ~i; --i) {
      if (x & (1ll << i)) {
        if (!a[i]) {
          a[i] = x;
          return;
        } else {
          x ^= a[i];
        }
      }
    }
    flag = true;
  }

  bool check(int x) {
    for (int i = N; ~i; --i) {
      if (x & (1ll << i)) {
        if (!a[i]) {
          return false;
        } else {
          x ^= a[i];
        }
      }
    }
    return true;
  }

  int qmax() {
    int res = 0;
    for (int i = N; ~i; --i) {
      res = max(res, res ^ a[i]);
    }
    return res;
  }

  int qmin() {
    if (flag) {
      return 0;
    }
    for (int i = 0; i <= N; ++i) {
      if (a[i]) {
        return a[i];
      }
    }
    throw 114514;
  }

  int rank(int k) {
    int res = 0;
    int cnt = 0;
    k -= flag;
    if (!k) {
      return 0;
    }
    for (int i = 0; i <= N; ++i) {
      for (int j = i - 1; ~j; --j) {
        if (a[i] & (1ll << j)) {
          a[i] ^= a[j];
        }
      }
      if (a[i]) {
        tmp[cnt++] = a[i];
      }
    }
    if (k >= (1ll << cnt)) {
      return -1;
    }
    for (int i = 0; i < cnt; ++i) {
      if (k & (1ll << i)) {
        res ^= tmp[i];
      }
    }
    return res;
  }

  int size() {
    int sz = 0;
    while (true) {
      ++sz;
      if (rank(sz) == -1) {
        return sz - 1;
      }
    }
    throw 1919810;
  }
};

void solve() {
  int n, A = 0, B = 0, C = 0, ans = 1e15;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
    A = A ^ i;
  }
  for (auto &j : b) {
    cin >> j;
    B = B ^ j;
  }
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = a[i] ^ b[i];
    C = C ^ a[i];
  }
  XXJ t;
  for (auto i : c) {
    t.insert(i);
  }
  // for (int i = 32; i >= 0; --i) {
  //   cout << t.a[i] << ' ';
  // }
  // cout << endl;
  for (int i = 32; i >= 0; --i) {
    // cout << A << ' ' << B << endl;

    int ba = (A >> i) & 1;
    int bb = (B >> i) & 1;
    if (ba ^ bb) {
      if (ba != 0) {
        B ^= t.a[i];
      } else {
        A ^= t.a[i];
      }
      // cout << "mid: " << A << ' ' << B << endl;
      for (int j = i - 1; j >= 0; --j) {
        if (((A >> j) & 1) == 1) {
          A ^= t.a[j];
        }
        // cout << t.a[j] << ' ';
      }
      // cout << endl;
      int as1 = A;
      for (int j = i - 1; j >= 0; --j) {
        if (((B >> j) & 1) == 1) {
          B ^= t.a[j];
        }
      }
      int as2 = B;
      ans = min(ans, min(A, B));
      // cout << "break: " << A << ' ' << B << endl;
      break;
    } else if (ba == 1) {
      A ^= t.a[i];
      B ^= t.a[i];
      ans = min(ans, max(A, B));
    }
  }
  ans = min(ans, max(A, B));
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}