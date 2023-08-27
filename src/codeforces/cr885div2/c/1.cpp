#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

int gcd(int a, int b) {
  if (a == 0) {
    return 0;
  }
  if (b == 0) {
    return 1;
  }
  if (a >= b) {
    int r = a % b;
    int k = a / b;
    if (k % 2 == 1) {
      return gcd(b, r) + k + k / 2;
    } else {
      return gcd(r, b) + k + k / 2;
    }
  }
  return 1 + gcd(b, abs(a - b));
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  set<int> cnt;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0 && b[i] == 0) {
      continue;
    }
    cnt.insert(gcd(a[i], b[i]) % 3);
  }
  cout << (cnt.size() <= 1 ? "YES" : "NO") << endl;
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
