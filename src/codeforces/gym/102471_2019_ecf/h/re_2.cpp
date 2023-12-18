#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

#define endl "\n"

int qmi(int x, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = res * x % p;
    }
    k >>= 1;
    x = x * x % p;
  }
  return res;
}

int getR(int l, int r) { return rand() % (r - l + 1) + l; }

int inv(int x, int p) { return qmi(x, p - 2, p); }

void solve() {
  int n, p;
  cin >> n >> p;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, n - 3);
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    i %= p;
  }
  auto check = [&](int p1, int p2) {
    if (p2 >= n) {
      return 0ll;
    }
    int q = a[p2] * inv(a[p1], p) % p;
    int cnt = 2;
    int target = q * a[p2] % p;
    for (int i = p2 + 1; i < a.size(); ++i) {
      if (a[i] == target) {
        ++cnt;
        target = q * a[i] % p;
      }
    }
    target = a[p1] * inv(q, p) % p;
    for (int i = p1 - 1; i >= 0; --i) {
      if (a[i] == target) {
        ++cnt;
        target = a[i] * inv(q, p) % p;
      }
    }
    return cnt;
  };
  int ans = 0;
  for (int qwq = 1; qwq <= 30; ++qwq) {
    int i = dis(gen);
    ans = max(ans, check(i, i + 1));
    ans = max(ans, check(i, i + 2));
  }
  if (ans < (n + 1) / 2) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
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
