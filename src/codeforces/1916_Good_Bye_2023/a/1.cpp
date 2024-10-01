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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int tot = 1;
  for (auto &i : a) {
    cin >> i;
    tot *= i;
  }
  vector<int> ans;
  function<void(int, int, vector<int>)> dfs
    = [&](int s, int cur, vector<int> a) {
        if (s == k + 1) {
          if (cur == 2023) {
            ans = a;
          }
          return;
        }
        for (auto x : {1, 7, 17, 119, 289, 2023}) {
          a.emplace_back(x);
          dfs(s + 1, cur * x, a);
          a.pop_back();
        }
      };
  dfs(1, tot, vector<int>());
  if (ans.size() == k) {
    cout << "YES\n";
    for (auto i : ans) {
      cout << i << ' ';
    }
    cout << endl;
  } else {
    cout << "NO\n";
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
