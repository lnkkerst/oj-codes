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
  int n, m, p;
  cin >> n >> m >> p;
  if (n == 1) {
    cout << "YangQiShaoNian" << endl;
    return;
  }
  if (m >= n + 1) {
    cout << "XiaoNian" << endl;
    return;
  }
  if (p == 1) {
    cout << "YangQiShaoNian" << endl;
    return;
  }
  cout << "XiaoNian" << endl;
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
