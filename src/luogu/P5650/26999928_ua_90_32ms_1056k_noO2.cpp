#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  cin >> s;
  int last = 0, ans = 0;
  for (int i = 0; i <= (int)s.length(); ++i) {
    last = max(0, last) + (s[i] == '0' ? 1 : -1);
    ans = max(ans, last);
  }
  cout << ans;
  return 0;
}