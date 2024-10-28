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

void solve() {
  cout << "? ";
  for (int i = 1; i <= 100; ++i) {
    cout << i << ' ';
  }
  cout << endl;
  int x1;
  cin >> x1;
  cout << "? ";
  for (int i = 1; i <= 100; ++i) {
    cout << (i << 7) << ' ';
  }
  cout << endl;
  int x2;
  cin >> x2;
  cout << "! " << ((x1 >> 7) << 7) + (x2 & 0b1111111) << endl;
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
