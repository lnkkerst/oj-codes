#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

#define int long long

void solve() {
  int n;
  cin >> n;
  deque<int> a(n);
  int tot = 0;
  for (auto &i : a) {
    cin >> i;
    tot += i;
  }
  sort(a.begin(), a.end());
  int mi = a.front(), ma = a.back();
  tot -= mi + ma;
  a.pop_front();
  if (set<int>{a.begin(), a.end()}.size() == 1) {
    cout << tot << endl;
  } else {
    cout << tot + 1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
