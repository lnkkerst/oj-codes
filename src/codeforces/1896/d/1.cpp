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

#define endl "\n"

void solve() {
  int n, q;
  cin >> n >> q;
  multiset<int> b;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      b.insert(i);
    }
  }
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x;
      cin >> x;
      if ((x - b.size()) & 1) {
        if (b.empty()) {
          cout << "NO" << endl;
          continue;
        }
        int s1 = 2 * *b.rbegin() - 2 - (b.size() - 1);
        int s2 = 2 * (n - *b.begin()) - (b.size() - 1);
        if (x <= max(s1, s2)) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
        continue;
      }
      if (x <= 2 * n - b.size()) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }

    } else {
      int pos, x;
      cin >> pos >> x;
      b.erase(pos);
      if (x == 1) {
        b.insert(pos);
      }
    }
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
