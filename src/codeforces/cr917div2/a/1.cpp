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

int sgn(int x) { return x < 0 ? -1 : x > 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> b;
  for (auto &i : a) {
    cin >> i;
    ++b[sgn(i)];
  }
  if (b[-1] & 1) {
    cout << 0 << endl;
    return;
  }
  if (b[0]) {
    cout << "0" << endl;
    return;
  }
  cout << "1\n1 0" << endl;
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
