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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  auto b = a;
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  auto ra = a;
  for (auto &i : ra) {
    for (auto &j : i) {
      if (j == 'X') {
        j = '.';
      } else {
        j = 'X';
      }
    }
  }
  auto count = [&](vector<string> &a) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] != b[i][j]) {
          ++cnt;
        }
      }
    }
    return cnt;
  };
  auto print = [&](vector<string> &a) {
    for (auto &i : a) {
      cout << i << endl;
    }
  };
  int ma = n * m / 2;
  if (count(a) <= ma) {
    print(a);
  } else if (count(ra) <= ma) {
    print(ra);
  } else {
    cout << -1 << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
