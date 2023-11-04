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
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 1) {
    cout << m << endl;
    return;
  }
  if (k & 1) {
    int ggroup = m * 2 / (k - 1);
    if (n == ggroup) {
      cout << m - (ggroup * (k - 1) / 2) << endl;
      return;
    }
    if (n > ggroup) {
      int brest = n - ggroup;
      int grest = m - (ggroup * (k - 1) / 2);
      brest %= k;
      if (brest + grest * 2 >= k) {
        brest -= k - grest * 2;
        grest = 0;
      }
      int sw = min(brest / 2, m - grest);
      brest -= sw * 2;
      grest += sw;
      cout << brest + grest << endl;
      return;
    }
    if (n < ggroup) {
      cout << m - (n * (k - 1) / 2) << endl;
      return;
    }
    int tgroup = min(n, ggroup);
    int mgroup = min(n, tgroup);
    int brest = n - mgroup;
    int grest = (m * 2 - (k - 1) * mgroup) / 2;
    if (brest) {
      int bc = (brest - 1) / 2;
      if (bc + grest >= k / 2) {
        brest -= k - grest * 2;
        grest = 0;
      }
    }
    brest %= k;
    cout << brest + grest << endl;
  } else {
    int bgroup = n / k;
    int brest = n % k;
    int ggroup = m * 2 / k;
    int grest = ((m * 2) % k) / 2;
    int bc = brest / 2;
    if (bc + grest >= k / 2) {
      brest -= bc * 2;
      grest -= (k / 2) - bc;
    }
    int sw = min(brest / 2, m - grest);
    brest -= sw * 2;
    grest += sw;
    cout << brest + grest << endl;
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
