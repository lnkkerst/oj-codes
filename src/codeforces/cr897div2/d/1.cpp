#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> b(n);
  vector<int> clr(n);
  for (auto &i : b) {
    cin >> i;
  }
  if (k == 1) {
    if ([&]() {
          for (int i = 0; i < n; ++i) {
            if (b[i] != i + 1) {
              return false;
            }
          }
          return true;
        }()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return;
  }
  int cc = 1;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (clr[i]) {
      continue;
    }
    int u = i;
    int cn = 0;
    while (!clr[u]) {
      clr[u] = cc;
      a[u] = cn;
      ++cn;
      u = b[u] - 1;
    }
    if (clr[u] != cc) {
      ++cc;
      continue;
    }
    if (cn - a[u] != k) {
      cout << "NO" << endl;
      return;
    }
    ++cc;
  }
  cout << "YES" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
