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
  set<int> b;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    b.insert(x);
  }
  if (b.size() == 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  cout << "BR";
  for (int i = 1; i <= n - 2; ++i) {
    cout << "B";
  }
  cout << endl;
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
