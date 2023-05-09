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

int fastPow(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= MOD;
    }
    k >>= 1;
    x *= x;
    x %= MOD;
  }
  return res;
}

void solve() {
  int n, c;
  scanf("%lld%lld", &n, &c);
  int cnt = 0;
  for (auto i : prime) {
    if (i * i > n) {
      break;
    }
    while (n % i == 0) {
      ++cnt;
      n /= i;
    }
  }
  printf("%lld\n", fastPow(c, cnt + (n != 1)));
}

signed main() {
  init();
  int t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
