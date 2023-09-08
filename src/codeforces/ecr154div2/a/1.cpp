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
  string s;
  cin >> s;
  int p1 = -1, p3 = -1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '1') {
      p1 = i;
    }
    if (s[i] == '3') {
      p3 = i;
    }
  }
  if (p3 > p1) {
    cout << 13 << endl;
  } else {
    cout << 31 << endl;
  }
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
