#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define int long long
using namespace std;

int work(int x) {
  int ret = 1;
  while (x != 1) {
    ++ret;
    if (x & 1)
      x *= 3, ++x;
    else
      x >>= 1;
  }
  return ret;
}

signed main() {
  int l, r;
  while (scanf("%lld%lld", &l, &r) != EOF) {
    int ans = -1;
    for (int i = l; i <= r; ++i)
      ans = max(work(i), ans);
    printf("%lld %lld %lld\n", l, r, ans);
  }
  return 0;
}