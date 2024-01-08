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
#define endl "\n"

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int x = 1, c = 1, c0 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ++x;
      ++c;
    }
    if (a[i] == -1) {
      if (c < 2) {
        if (c0) {
          c += 2;
          ++x;
          --c0;
        } else {
          cout << -1 << endl;
          return;
        }
      }
      --c;
    }
    if (a[i] == 0) {
      if (c >= 2) {
        --c;
        ++c0;
      } else {
        ++x;
        ++c;
      }
    }
  }
  int g = gcd(x, c);
  x /= g;
  c /= g;
  cout << x << ' ' << c << endl;
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
