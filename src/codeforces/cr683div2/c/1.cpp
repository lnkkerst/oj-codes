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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if (s[0] != s[k - 1]) {
    cout << s[k - 1] << endl;
    return;
  }
  cout << s[0];
  if (s[k] != s[n - 1]) {
    for (int i = k; i < n; ++i) {
      cout << s[i];
    }
  } else {
    for (int i = 0; i < (n - k + k - 1) / k; ++i) {
      cout << s[n - 1];
    }
  }
  cout << endl;
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
