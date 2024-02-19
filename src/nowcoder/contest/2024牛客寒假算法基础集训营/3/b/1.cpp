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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int c0 = 0, c1 = 0;
  for (auto &i : a) {
    cin >> i;
    i = i & 1;
  }
  int cnt = a.front() != a.back();
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      ++cnt;
    }
  }
  if (cnt == 1) {
    if (n & 1) {
      cout << "qcjj" << endl;
    } else {
      cout << "zn" << endl;
    }
    return;
  }
  if ((n - cnt) & 1) {
    cout << "qcjj" << endl;
  } else {
    cout << "zn" << endl;
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
