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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int l = 1, r = 1e10;
  for (int qwq = 1; qwq <= 50; ++qwq) {
    int mid = (l + r) / 2;
    int cnt = 0;
    for (auto x : a) {
      auto it = upper_bound(b.begin(), b.end(), mid - x);
      int index = distance(b.begin(), it);
      cnt += index;
    }
    if (cnt < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << r << endl;
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
