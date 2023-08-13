#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  string c, s;
  cin >> n >> c >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] < c[0]) {
      s.insert(i, c);
      cout << s << endl;
      return;
    }
  }
  s += c;
  cout << s << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
