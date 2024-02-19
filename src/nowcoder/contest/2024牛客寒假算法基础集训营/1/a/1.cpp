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
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t1 = "SFD";
  string t2 = "sfd";
  map<int, int> b;
  for (auto c : s) {
    if (!t1.empty() && c == t1.back()) {
      t1.pop_back();
    }
    if (!t2.empty() && c == t2.back()) {
      t2.pop_back();
    }
  }
  if (t1.empty()) {
    cout << 1 << ' ';
  } else {
    cout << 0 << ' ';
  }
  if (t2.empty()) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
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
