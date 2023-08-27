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
  string s0, s1;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      s1 += s[i];
    } else {
      s0 += s[i];
    }
  }
  sort(s0.begin(), s0.end(), greater<>());
  sort(s1.begin(), s1.end(), greater<>());
  string as;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      as += s1.back();
      s1.pop_back();
    } else {
      as += s0.back();
      s0.pop_back();
    }
  }
  if (k & 1) {
    cout << as << endl;
    return;
  }
  sort(s.begin(), s.end());
  cout << s << endl;
  return;
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
