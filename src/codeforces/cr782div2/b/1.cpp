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
  string s;
  cin >> s;
  vector<int> a(n);
  int rk = k;
  for (int i = 0; i < n && rk; ++i) {
    a[i] = !(k & 1) ^ (s[i] == '1');
    if (a[i]) {
      --rk;
    }
  }
  a.back() += rk;
  for (int i = 0; i < n; ++i) {
    if ((k - a[i]) & 1) {
      s[i] = s[i] == '1' ? '0' : '1';
    }
  }
  cout << s << endl;
  for (auto i : a) {
    cout << i << ' ';
  }
  cout << endl;
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
