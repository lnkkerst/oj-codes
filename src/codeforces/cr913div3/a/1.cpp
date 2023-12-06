#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  set<string> b;
  for (char i = '1'; i <= '8'; ++i) {
    b.insert(string("") + s[0] + i);
  }
  for (char i = 'a'; i <= 'h'; ++i) {
    b.insert(string("") + i + s[1]);
  }
  b.erase(s);
  for (auto i : b) {
    cout << i << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
