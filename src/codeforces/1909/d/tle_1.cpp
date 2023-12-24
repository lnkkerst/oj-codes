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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long
#define endl '\n'

int sgn(int x) {
  if (x == 0) {
    return 0;
  }
  if (x > 0) {
    return 1;
  } else {
    return -1;
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b;
  set<int> bs;
  for (auto &i : a) {
    cin >> i;
    bs.insert(i);
  }
  if (bs.size() == 1) {
    cout << 0 << endl;
    return;
  }
  b.clear();
  for (int i = 0; i * i <= abs(a[0] - k); ++i) {
    if (a[0] == k) {
      break;
    }
    if (abs(a[0] - k) % (i + 1) == 0) {
      if (a[0] >= k) {
        b.emplace_back(k + abs(a[0] - k) / (i + 1));
        b.emplace_back(k + abs(a[0] - k) / (abs(a[0] - k) / (i + 1)));
      } else {
        b.emplace_back(k - abs(a[0] - k) / (i + 1));
        b.emplace_back(k - abs(a[0] - k) / (abs(a[0] - k) / (i + 1)));
      }
    }
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  auto filter = [&](int ai) {
    vector<int> nb;
    for (auto x : b) {
      if (x == k) {
        continue;
      }
      if (x != ai && sgn(x - ai) != sgn(k - x)) {
        continue;
      }
      if (abs(x - ai) % abs(k - x) != 0) {
        continue;
      }
      nb.emplace_back(x);
    }
    b = nb;
  };
  filter(*max_element(a.begin(), a.end()));
  filter(*min_element(a.begin(), a.end()));
  shuffle(a.begin(), a.end(), default_random_engine());
  for (int i = 0; i < n; ++i) {
    filter(a[i]);
  }
  if (b.empty()) {
    cout << -1 << endl;
    return;
  }
  int ans = 1e18;
  for (auto x : b) {
    int t = 0;
    for (auto i : a) {
      t += (x - i) / (k - x);
    }
    ans = min(ans, t);
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
