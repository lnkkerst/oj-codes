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
  string s;
  cin >> s;
  set<char> ans;
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      int as = 0, bs = 0;
      int ass = 0, bss = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
          ++as;
          if (as == x) {
            ++ass;
            as = 0;
            bs = 0;
            if (ass == y) {
              if (i == n - 1) {
                ans.insert('A');
              } else {
                break;
              }
            }
          }
        } else {
          ++bs;
          if (bs == x) {
            ++bss;
            as = 0;
            bs = 0;
            if (bss == y) {
              if (i == n - 1) {
                ans.insert('B');
              } else {
                break;
              }
            }
          }
        }
      }
    }
  }
  if (ans.size() == 1) {
    cout << *ans.begin() << endl;
  } else {
    cout << "?" << endl;
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
