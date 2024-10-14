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

#define int long long

void solve() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, function<bool(int, int)>> a(
    [](int a, int b) {
      return a > b;
    });
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.push(x);
  }
  while (a.size() > 1) {
    int x = a.top();
    a.pop();
    int y = a.top();
    a.pop();
    a.push((x + y) / 2);
  }
  cout << a.top() << endl;
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
