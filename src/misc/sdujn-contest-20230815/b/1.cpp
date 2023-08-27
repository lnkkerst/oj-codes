#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define int long long

constexpr int MOD = (int)1e9 + 7;

int fastPow(int x, int k, int p = MOD) {
  x %= MOD;
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= p;
    }
    x *= x;
    x %= p;
    k >>= 1;
  }
  return res % p;
}

signed main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  queue<int> q;
  int pos = 0;
  for (auto i : a) {
    while (!q.empty() && i - q.front() >= k) {
      q.pop();
    }
    q.push(i);
    cout << q.size() << ' ' << pos << endl;
    ans += fastPow(2, pos + 1 - q.size());
    ans %= MOD;
    ++pos;
  }
  cout << ans;
}
