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
  string s;
  cin >> s;
  int n = s.length();
  vector<int> a;
  set<int> b;
  int mi = 0;
  int ma = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      ++cnt;
    }
    if (s[i] == '-') {
      --cnt;
      ma = min(ma, cnt);
      if (cnt < mi) {
        mi = 0;
      }
    }
    if (s[i] == '0') {
      if (cnt < 2) {
        cout << "NO" << endl;
        return;
      }
      if (mi == 0 || cnt < mi) {
        mi = cnt;
      }
    }
    if (s[i] == '1') {
      ma = max(cnt, ma);
    }
    if (mi <= ma && mi != 0) {
      cout << "NO" << endl;
      return;
    }
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
