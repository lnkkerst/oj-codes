#pragma GCC optimize(2)

#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

#define int long long

constexpr int MAXP = 1e9;
constexpr int MAXN = 1e5;

int prime[MAXN], cntp = 0;
bool notPrime[MAXN];

void sieve() {
  notPrime[1] = true;
  for (int i = 2; i * i <= MAXP; ++i) {
    if (!notPrime[i]) {
      prime[++cntp] = i;
      for (int j = i * 2; j * j <= MAXP; j += i) {
        notPrime[j] = true;
      }
    }
  }
}

void solve() {
  int n;
  scanf("%lld", &n);
  vector<int> a(n);
  int cnt2 = 0;
  for (auto &i : a) {
    scanf("%lld", &i);
    if (i % 2 == 0) {
      ++cnt2;
    }
  }
  if (cnt2 >= 2) {
    puts("YES");
    return;
  }
  sort(a.begin(), a.end(), greater<>());
  if (a.back() == 1) {
    a.pop_back();
  }
  unordered_map<int, int> cnt;
  unordered_map<int, int> cnth;
  for (auto x : a) {
    for (int i = 1; i <= cntp; ++i) {
      if (prime[i] > x) {
        break;
      }
      if (x % prime[i] == 0) {
        ++cnt[prime[i]];
        if (cnt[prime[i]] >= 2) {
          puts("YES");
          return;
        }
        while (x % prime[i] == 0) {
          x /= prime[i];
        }
      }
    }
    if (x > 1) {
      if (cnth[x]) {
        puts("YES");
        return;
      }
      cnth[x] = 1;
    }
  }
  puts("NO");
}

signed main() {
  sieve();
  int t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
