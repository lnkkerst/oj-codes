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
  set<int> b;
  for (auto &i : a) {
    cin >> i;
    b.insert(i);
  }
  for (auto i : a) {
    for (auto j : a) {
      if (b.find(i - j) != b.end() || b.find(j - i) != b.end()) {
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
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
