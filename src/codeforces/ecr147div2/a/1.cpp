#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int ans = 1;
  if (s[0] == '0') {
    cout << 0 << endl;
    return;
  }
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '?') {
      if (i == 0) {
        ans *= 9;
      } else {
        ans *= 10;
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
