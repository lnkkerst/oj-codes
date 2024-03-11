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

vector<int> prime;
vector<int> notPrime(3e6 + 1);

void init() {
  notPrime[1] = 1;
  for (int i = 2; i <= 3e6; ++i) {
    if (!notPrime[i]) {
      prime.emplace_back(i);
      for (int j = i * 2; j <= 3e6; j += i) {
        notPrime[j] = 1;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n + 1);
  int cur = n;
  while (cur >= 1) {
    auto it = upper_bound(prime.begin(), prime.end(), cur);
    int l = *it - cur;
    if (l > cur) {
      cout << -1 << endl;
      return;
    }
    for (int i = l; i <= cur; ++i) {
      ans[i] = cur - (i - l);
    }
    cur = l - 1;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int t = 1;
  while (t--) {
    solve();
  }
}
