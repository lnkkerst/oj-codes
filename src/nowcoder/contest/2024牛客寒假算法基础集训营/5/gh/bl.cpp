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

bool pd(int x) {
  if (x == 1) {
    return false;
  }
  if (x == 2) {
    return true;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  do {
    bool fl = true;
    for (int i = 0; i < n; ++i) {
      if (!pd(a[i] + i + 1)) {
        fl = false;
        break;
      }
    }
    if (fl) {
      for (auto i : a) {
        cout << i << ' ';
      }
      cout << endl;
    }
  } while (next_permutation(a.begin(), a.end()));
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
