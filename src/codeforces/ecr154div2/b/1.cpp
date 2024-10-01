#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.length();
  for (int i = 0; i < n - 1; ++i) {
    if (s1[i] == s2[i] && s1[i] == '0' && s1[i + 1] == s2[i + 1]
        && s1[i + 1] == '1') {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
