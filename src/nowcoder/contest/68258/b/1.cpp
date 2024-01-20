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
  int l, r, k;
  cin >> l >> r >> k;
  if (k == 0) {
    cout << (r - l + 1) % 2 << endl;
    return;
  }
  int len = r - l + 1;
  if (len % 2 == 0) {
    cout << (len / 2) % 2 << endl;
    return;
  }
  if (l & 1) {
    cout << (len / 2 + 1) % 2 << endl;
  } else {
    cout << (len / 2) % 2 << endl;
  }
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
