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
  map<int, int> b;
  for (int i = 'a'; i <= 'z'; ++i) {
    b[i] = false;
  }
  int m = 0;
  for (auto &i : s) {
    if (b[i]) {
      m += 2;
      for (int j = 'a'; j <= 'z'; ++j) {
        b[j] = false;
      }
    } else {
      b[i] = true;
    }
  }
  cout << s.size() - m << endl;
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
