#pragma GCC optimize(2)
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int x, t, k, n, d;
  cin >> x >> t >> k >> n >> d;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int inc = 0;
  int cur = x;
  int cnt = 0;
  for (auto i : a) {
    if (i <= d) {
      --inc;
    } else {
      ++inc;
    }
  }
  if (inc < 0) {
    cout << "YES" << endl;
    return;
  }
  if (inc == 0) {
    bool fl = false;
    int cur = x;
    for (int j = 0; j < 2; ++j) {
      for (auto i : a) {
        if (i <= d) {
          --cur;
        } else {
          ++cur;
        }
        if (cur > k) {
          fl = true;
          break;
        }
      }
    }
    if (!fl && x <= k) {
      cout << "YES" << endl;
      return;
    }
  }
  if (inc > 0) {
    int pturn = max(0ll, k - x);
    int turn = pturn / inc;
    cnt += turn * n;
    cur += turn * inc;
  }
  for (int j = 0; j < 10; ++j) {
    for (auto i : a) {
      if (i <= d) {
        --cur;
      } else {
        ++cur;
      }
      if (cur <= k) {
        ++cnt;
      } else {
        cnt = 0;
      }
      if (cnt >= t) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
