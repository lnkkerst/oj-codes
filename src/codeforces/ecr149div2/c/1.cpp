#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  string s, ss;
  cin >> ss;
  s = ss;
  int n = s.length();
  int pos = n - 1;
  vector<char> ans(n);
  int lzp = -1;
  while (pos >= 0) {
    if (s[pos] == '?') {
      s[pos] = '1';
      ans[pos] = '1';
      --pos;
    } else if (s[pos] == '1') {
      --pos;
    } else {
      int np = pos - 1;
      if (lzp != -1) {
        np = lzp;
      }
      while (np >= 0) {
        if (s[np] == '?') {
          s[np] = '0';
          ans[np] = '0';
        }
        if (s[np] == '1') {
          break;
        }
        --np;
      }
      if (np < 0) {
        break;
      }
      int zp = np + 1;
      while (np >= 0) {
        if (s[np] == '?') {
          s[np] = '1';
          ans[np] = '1';
        }
        if (s[np] == '0') {
          break;
        }
        --np;
      }
      ++np;
      if (np < 0) {
        np = 0;
      }
      reverse(s.begin() + np, s.begin() + pos + 1);
      pos -= (zp - np);
      lzp = np;
      if (zp == np) {
        --pos;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (ss[i] == '?') {
      cout << ans[i];
    } else {
      cout << ss[i];
    }
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
