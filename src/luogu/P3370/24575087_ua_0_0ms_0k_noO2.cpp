#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int k = 131;
int a[10010];

int read() {
  int ret;
  char ch;
  bool f;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return f ? -ret : ret;
}

int bkdrhs(string s) {
  int l = s.length();
  int ret = 0;
  for (int i = 0; i < l; ++i)
    ret = (1ll * ret * k + s[i]) % MOD;
  return ret;
}

int main() {
  int n = read();
  string s;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    a[i] = bkdrhs(s);
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 2; i <= n; ++i)
    if (a[i] != a[i - 1])
      ans++;
  cout << ans + 1 << endl;
  return 0;
}