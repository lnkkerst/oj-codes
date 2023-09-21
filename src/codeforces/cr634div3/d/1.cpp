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
  while (cin >> s) {
    for (auto &i : s) {
      if (i == '2') {
        i = '1';
      }
    }
    cout << s << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
