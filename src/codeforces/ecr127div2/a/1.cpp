#include <iostream>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int cnt = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      ++cnt;
    } else {
      if (cnt == 1) {
        cout << "NO" << endl;
        return;
      } else {
        cnt = 1;
      }
    }
  }
  if (cnt == 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
