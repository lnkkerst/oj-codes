#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  if (s == "^") {
    cout << 1 << endl;
    return;
  }
  s = ' ' + s + ' ';
  int ans = 0;
  if (s[1] == '_') {
    ++ans;
  }
  bool fl = false;
  for (int i = 1; i < s.size() - 1; ++i) {
    if (s[i] == '_') {
      if (s[i + 1] != '^') {
        ++ans;
      }
    }
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
