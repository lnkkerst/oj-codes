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

constexpr int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int y;
  cin >> y;
  set<int> b;
  for (int i = '0'; i <= '9'; ++i) {
    for (int j = '0'; j <= '9'; ++j) {
      for (int k = '0'; k <= '9'; ++k) {
        for (int l = '0'; l <= '9'; ++l) {
          for (int m = '0'; m <= '9'; ++m) {
            if (i == j || i == k || i == l || j == k || j == l || k == l) {
              continue;
            }
            auto ns = s;
            for (auto &c : ns) {
              if (c == 'a') {
                c = i;
              } else if (c == 'b') {
                c = j;
              } else if (c == 'c') {
                c = k;
              } else if (c == 'd') {
                c = l;
              } else if (c == '_') {
                c = m;
              }
            }
            if (ns.size() != 1 && ns.front() == '0') {
              continue;
            }
            int x = stoi(ns);
            if (x > y) {
              continue;
            }
            if (x % 8 != 0) {
              continue;
            }

            b.insert(x);
          }
        }
      }
    }
  }
  cout << b.size() << endl;
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
