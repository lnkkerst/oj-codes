#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = " " + s;
  vector<int> a(256);
  for (int i = 1; i <= n; ++i) {
    while (s[i] != 'a' && a[s[i]]) {
      --s[i];
    }
    while (k && s[i] != 'a') {
      --k;
      ++a[s[i]];
      --s[i];
      while (s[i] != 'a' && a[s[i]]) {
        --s[i];
      }
    }
  }
  cout << s.data() + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
