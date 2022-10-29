#include <cstdio>
#define int long long

void exgcd(int a, int b, int &x, int &y, int &d) {
  if (!b) {
    d = a;
    y = 0;
    x = 1;
    return;
  }
  exgcd(b, a % b, y, x, d), y -= (a / b) * x;
}

signed main() {
  int a, b, s, x = 0, y = 0, d;
  scanf("%lld%lld%lld", &a, &b, &s);
  exgcd(a, b, x, y, d);
  y += (a / b) * x;
  if (s % d) {
    puts("NO");
    return 0;
  }
  int b1 = b / d;
  int x1 = (x + b1) * (s / d);
  x1 = (x1 % b1 + b1) % b1;
  int y1 = (s - a * x1) / b;
  if (!x1) {
    puts("NO");
    return 0;
  }
  for (int i = 2; i * i <= x1; ++i) {
    if (x1 % i == 0) {
      if (y1 % i == 0) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}