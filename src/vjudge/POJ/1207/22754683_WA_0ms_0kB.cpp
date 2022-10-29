#include <iostream>
using namespace std;

int a[100010];

int calc(int x) {
  if (a[x])
    return a[x];
  int t = x;
  while (t != 1) {
    ++a[x];
    if (t & 1)
      t *= 3, ++t;
    else
      t >>= 1;
  }
  ++a[x];
  return a[x];
}

int main() {
  int l, r;
  while (cin >> l >> r) {
    int ans = -1;
    for (int i = l; i <= r; ++i)
      ans = max(ans, calc(i));
    cout << l << ' ' << r << ' ' << ans << '\n';
  }
  return 0;
}