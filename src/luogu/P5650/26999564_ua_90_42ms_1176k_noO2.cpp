#include <bits/stdc++.h>
using namespace std;

int s[233333];
int len;

int main() {
  char ch;
  while (cin >> ch) {
    s[++len] = ch == '0' ? 1 : -1;
  }
  int last = 0, ans = 0;
  for (int i = 1; i <= len; ++i) {
    last = max(0, last) + s[i];
    ans = max(ans, last);
  }
  cout << ans;
  return 0;
}
