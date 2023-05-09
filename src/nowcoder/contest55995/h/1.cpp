#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#define int long long
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e6;

vector<int> prime;
bool notPrime[MAXN + 10];
int cnt[MAXN + 10];

void init() {
  notPrime[1] = true;
  for (int i = 2; i <= MAXN; ++i) {
    if (!notPrime[i]) {
      prime.emplace_back(i);
      for (int j = i * 2; j <= MAXN; j += i) {
        notPrime[j] = true;
      }
    }
  }
}

void solve() {
  int n;
  scanf("%lld", &n);
  vector<int> a, b;
  unordered_map<int, bool> bk;
  auto ite = upper_bound(prime.begin(), prime.end(), n / 2);
  for (auto it = ite - 1; it >= prime.begin(); --it) {
    auto i = *it;
    if (i * 2 > n) {
      continue;
    }
    vector<int> pp;
    for (int j = i; j <= n; j += i) {
      if (bk[j]) {
        continue;
      }
      pp.emplace_back(j);
    }
    if (pp.size() & 1) {
      for (int j = 0; j < pp.size(); ++j) {
        if (pp[j] % 2 == 0) {
          pp.erase(pp.begin() + j);
          break;
        }
      }
    }
    for (int j = 1; j < pp.size(); j += 2) {
      a.emplace_back(pp[j]);
      b.emplace_back(pp[j - 1]);
      bk[pp[j]] = bk[pp[j - 1]] = true;
    }
  }
  int sz = min(a.size(), b.size());
  printf("%lld\n", sz);
  for (int i = 0; i < sz; ++i) {
    printf("%lld %lld\n", a[i], b[i]);
  }
}

signed main() {
  init();
  int t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
