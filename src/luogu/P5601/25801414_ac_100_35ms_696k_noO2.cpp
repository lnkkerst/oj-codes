#include <bits/stdc++.h>
using namespace std;

map<string, string> ans;

int main() {
  int n, t;
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    string s1, s2;
    cin >> s1 >> s2;
    ans[s1] = s2;
  }
  for (int i = 1; i <= t; ++i) {
    string qus;
    cin >> qus;
    for (int j = 1; j <= 4; ++j) {
      string tans;
      cin >> tans;
      if (tans == ans[qus]) {
        cout << char(j + 'A' - 1) << endl;
        continue;
      }
    }
  }
  return 0;
}