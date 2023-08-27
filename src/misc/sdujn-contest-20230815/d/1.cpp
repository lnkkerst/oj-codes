#include <deque>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define int long long

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> a(s.length());
  a[0] = s[0] == '(' ? 1 : -1;
  for (int i = 1; i < n; ++i) {
    a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
  }
  if (a.back() != 0) {
    cout << "NO" << endl;
    return;
  }
  a.pop_back();
  for (auto i : a) {
    if (i <= 0) {
      cout << "NO" << endl;
      return;
    }
  }
  map<int, int> cnt;
  for (int i = 0; i < a.size(); ++i) {
    ++cnt[a[i]];
    auto it = cnt.find(a[i]);
    ++it;
    cnt.erase(it, cnt.end());
    if (cnt[a[i]] > 3) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
