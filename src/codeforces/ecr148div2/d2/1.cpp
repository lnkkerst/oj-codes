#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> aa(n);
  for (auto &i : aa) {
    cin >> i;
  }
  sort(aa.begin(), aa.end());
  auto a1 = aa;
  auto a2 = aa;
  for (int i = n, j = 1; i >= 1; --i, ++j) {
    a1[i - 1] += j;
  }
  for (int i = n - 1, j = 1; i >= 1; --i, ++j) {
    a2[i - 1] += j;
  }
  int su1 = 0;
  int mi1 = 1e18;
  for (auto i : a1) {
    su1 += i;
    mi1 = min(mi1, i);
  }
  int su2 = 0;
  int mi2 = 1e18;
  for (auto i : a2) {
    su2 += i;
    mi2 = min(mi2, i);
  }
  vector<int> ans1(n + 1, 2e18);
  int mia1 = aa.front();
  for (int i = 1; i <= n; ++i) {
    mia1 = min(mia1 + 1, aa[i - 1] + 1);
    if (i != n) {
      mia1 = min(mia1, aa[i]);
    }
    ans1[i] = mia1;
  }
  while (q--) {
    int k;
    cin >> k;
    if (k <= n) {
      cout << ans1[k] << ' ';
      continue;
    }
    int re = k - n;
    bool nf;
    if (re & 1) {
      ++re;
      nf = true;
    } else {
      nf = false;
    }
    int mi = (nf ? mi2 : mi1) + re;
    if (nf) {
      mi = min(mi, a2.back());
    }
    int su = (nf ? su2 : su1) + (aa.size() - nf) * re;
    int l = -1e18, r = 1e18;
    re /= 2;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      int cnt = su - mid * aa.size();
      bool fl = mi < mid;
      if (fl || cnt < re) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    cout << l << ' ';
  }
}

signed main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
