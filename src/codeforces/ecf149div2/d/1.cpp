#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  {
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto i : s) {
      if (i == '(') {
        ++cnt1;
      } else {
        ++cnt2;
      }
    }
    if (cnt1 != cnt2) {
      cout << -1 << endl;
      return;
    }
  }
  int colc = 0;
  vector<int> a(n);
  int curc = 1;
  bool fl = false;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == (curc == 1 ? '(' : ')')) {
      ++cnt;
    } else {
      --cnt;
    }
    // cout << cnt << endl;
    if (cnt < 0) {
      cnt = -cnt;
      curc = (curc == 1 ? 2 : 1);
    }
    a[i] = curc;
  }
  int sz = unordered_set<int>{a.begin(), a.end()}.size();
  cout << sz << endl;
  for (auto i : a) {
    cout << (sz == 1 ? 1 : i) << ' ';
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
