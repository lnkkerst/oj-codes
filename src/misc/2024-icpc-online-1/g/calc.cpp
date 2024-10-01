#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int tot = 0;
  for (int i = 1; i <= 2000; ++i) {
    int cur = 0;
    for (int j = i; j <= 2000; ++j) {
      tot += cur;
      ++cur;
    }
  }
  cout << tot << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
