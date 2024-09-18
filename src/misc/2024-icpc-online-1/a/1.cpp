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
  int n = 32;
  int cn;
  cin >> cn;
  int ls = 0;
  for (int i = 1; i <= 31; ++i) {
    int x;
    cin >> x;
    if (x < cn) {
      ++ls;
    }
  }
  if (ls >= 31) {
    cout << 1 << endl;
    return;
  }
  if (ls >= 27) {
    cout << 2 << endl;
    return;
  }
  if (ls >= 13) {
    cout << 4 << endl;
    return;
  }
  if (ls >= 6) {
    cout << 8 << endl;
    return;
  }
  if (ls >= 2) {
    cout << 16 << endl;
    return;
  }
  if (ls >= 0) {
    cout << 32 << endl;
    return;
  }
  throw 114514;
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
