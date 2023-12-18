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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  deque<pair<int, int>> q;
  vector<int> b(n + 1);
  int mex = 0;
  int su = 0;
  for (int i = 1; i <= n; ++i) {
    b[a[i]]++;
    while (b[mex]) {
      mex++;
    }
    q.emplace_back(mex, 1);
    su += mex;
  }
  int ans = su;
  for (int i = 1; i < n; ++i) {
    pair<int, int> t = {a[i], 0};
    su -= q.front().first;
    q.front().second--;
    if (q.front().second == 0) {
      q.pop_front();
    }
    while (!q.empty() && q.back().first >= a[i]) {
      su -= q.back().first * q.back().second;
      t.second += q.back().second;
      q.pop_back();
    }
    q.emplace_back(t);
    su = su + t.first * t.second;
    q.emplace_back(n, 1);
    su += n;
    ans = max(ans, su);
  }
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
