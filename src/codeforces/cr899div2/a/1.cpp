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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> b(n);
  map<int, int> bk;
  int ma = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = ma + 1; j <= 1000; ++j) {
      if (j != a[i] && !bk[j]) {
        b[i] = j;
        bk[j] = 1;
        ma = max(ma, j);
        break;
      }
    }
  }
  cout << *max_element(b.begin(), b.end()) << endl;
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
