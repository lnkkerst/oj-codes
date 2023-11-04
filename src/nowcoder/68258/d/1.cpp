#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  int curb = 0, curp = 0;
  set<int> b;
  while (true) {
    int tmp = (curp << 30) + curb;
    if (b.find(tmp) != b.end()) {
      cout << -1 << endl;
      return;
    }
    b.insert(tmp);
    int np = (n - curp + k - 1) / k * k - (n - curp);
    curb = !curb;
    for (int i = curp; i < n; i += k) {
      ans.emplace_back(i);
    }
    curp = np;
    if (curb && curp == 0) {
      break;
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i + 1 << ' ';
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
