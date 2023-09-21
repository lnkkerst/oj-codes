#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (a.front() != 0) {
    cout << 0 << endl;
    cout.flush();
    int y;
    cin >> y;
    return;
  }
  priority_queue<int> q;
  for (int i = 1; i < n; ++i) {
    if (a[i] - a[i - 1] != 1) {
      q.push(a[i - 1] + 1);
      break;
    }
  }
  if (q.empty()) {
    q.push(a.back() + 1);
  }
  while (!q.empty()) {
    int x = q.top();
    q.pop();
    cout << x << endl;
    cout.flush();
    int y;
    cin >> y;
    if (y == -1) {
      return;
    }
    if (y == -2) {
      exit(0);
    }
    q.push(y);
  }
  cout.flush();
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
