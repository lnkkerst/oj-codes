#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int pos0 = -1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '0') {
      pos0 = i;
      break;
    }
  }
  if (pos0 == -1) {
    pos0 = s.length();
  }
  int ans = pos0 != s.length();
  for (int i = pos0 - 1; i >= 0; --i) {
    if (s[i] == '1') {
      ++ans;
      break;
    }
    ++ans;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
