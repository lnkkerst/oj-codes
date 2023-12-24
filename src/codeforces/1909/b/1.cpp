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

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int c0 = 0;
  int c1 = 0;
  for (auto &i : a) {
    cin >> i;
    if (i & 1) {
      ++c1;
    } else {
      ++c0;
    }
  }
  int k = 2;
  while (true) {
    set<int> b;
    for (auto i : a) {
      b.insert(i % k);
      if (b.size() > 2) {
        break;
      }
    }
    if (b.size() == 2) {
      cout << k << endl;
      return;
    }
    k <<= 1;
  }
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
