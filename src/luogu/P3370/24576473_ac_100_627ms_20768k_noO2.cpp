#include <bits/stdc++.h>

using namespace std;

map<string, bool> a;

int main() {
  int n;
  cin >> n;
  string s[10010];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int ans = 1;
  sort(s + 1, s + n + 1);
  for (int i = 2; i <= n; ++i) {
    if (s[i] != s[i - 1]) {
      ans++;
    }
  }
  cout << ans << endl;
}
