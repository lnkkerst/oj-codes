// luogu-judger-enable-o2
#include <cmath>
#include <cstdio>
using namespace std;
bool ss(int x) {
  if (x % 2 == 0)
    return 0;
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0)
      return 0;
  return 1;
}
bool hws(int x) {
  int t = x, tmp = 0;
  while (x != 0) {
    tmp *= 10;
    tmp += x % 10;
    x /= 10;
  }
  if (tmp == t)
    return 1;
  else
    return 0;
}
int main() {
  int a, b;
  scanf("%ld%ld", &a, &b);
  if (b > 10000000)
    b = 10000000;
  for (int i = a; i <= b; i++)
    if (hws(i) == 1)
      if (ss(i) == 1)
        printf("%d\n", i);
  return 0;
}