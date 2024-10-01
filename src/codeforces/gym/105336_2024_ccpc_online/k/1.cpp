#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
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
  int p2 = 1;
  while (n % 2 == 0) {
    n /= 2;
    p2 *= 2;
  }
  if (p2 <= k) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
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
