#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  stack<int> s;
  vector<int> r(n), l(n);
  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && a[s.top()] < a[i]) {
      s.pop();
    }
    r[i] = s.empty() ? n : s.top();
    s.push(i);
  }

  reverse(a.begin(), a.end());

  s = stack<int>();
  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && a[s.top()] < a[i]) {
      s.pop();
    }
    l[i] = s.empty() ? -1 : s.top();
    s.push(i);
  }

  reverse(a.begin(), a.end());
  reverse(l.begin(), l.end());
  for (auto &x : l) {
    if (x != -1) {
      x = n - x - 1;
    }
  }

  // cout << "l: ";
  // for (auto i : l) {
  //   cout << i << ' ';
  // }
  // cout << endl;
  // cout << "r: ";
  // for (auto i : r) {
  //   cout << i << ' ';
  // }
  // cout << endl;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += i - l[i] - 1;
    if (r[i] >= n || a[r[i]] != a[i]) {
      ans += r[i] - i - 1;
    }
  }
  cout << ans << endl;
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
