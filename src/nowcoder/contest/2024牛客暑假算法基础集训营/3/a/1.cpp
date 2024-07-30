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
  int n, L, R;
  cin >> n >> L >> R;
  deque<int> a(n);
  deque<int> p;
  for (auto &i : a) {
    cin >> i;
    int tmp = (i - 1) / 2;
    if (tmp) {
      p.emplace_back(tmp);
    }
  }
  int rest = a.size() - p.size();
  deque<int> q;
  sort(p.begin(), p.end());
  int td = 0;
  while (true) {
    // cout << "Before:" << endl;
    // cout << "rest: " << rest << endl;
    // cout << "td: " << td << endl;
    // cout << "q:" << endl;
    // for (auto i : q) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    // cout << "p: " << endl;
    // for (auto i : p) {
    //   cout << i << ' ';
    // }
    // cout << endl;

    while (rest < R - L && (q.size() + p.size())) {
      if (!q.empty()) {
        ++rest;
        q.pop_front();
      } else {
        ++rest;
        p.pop_front();
      }
    }

    while (q.size() < L) {
      if (p.empty()) {
        if (rest + q.size() <= R) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
        return;
      }
      q.emplace_back(p.front() + td);
      p.pop_front();
    }
    int cur = min(rest, (R - L) * (q.front() - td));
    int cnt = (cur + R - L - 1) / (R - L);
    td += cnt;
    rest -= cur;
    while (!q.empty() && q.front() == td) {
      q.pop_front();
      ++rest;
    }

    // cout << "After:" << endl;
    // cout << "rest: " << rest << endl;
    // cout << "td: " << td << endl;
    // cout << "q:" << endl;
    // for (auto i : q) {
    //   cout << i << ' ';
    // }
    // cout << endl;
    // cout << "p: " << endl;
    // for (auto i : p) {
    //   cout << i << ' ';
    // }
    // cout << endl;
  }
  cout << "Yes" << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
