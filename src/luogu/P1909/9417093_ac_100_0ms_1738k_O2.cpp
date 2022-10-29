// luogu-judger-enable-o2
#include <cstdio>
using namespace std;
int main() {
  int n, x, y, m;
  scanf("%d", &n);
  scanf("%d%d", &x, &y);
  if (n < x)
    x = 1;
  else if (n % x != 0)
    x = n / x + 1;
  else
    x = n / x;
  x = x * y;
  m = x;
  scanf("%d%d", &x, &y);
  if (n < x)
    x = 1;
  else if (n % x != 0)
    x = n / x + 1;
  else
    x = n / x;
  x = x * y;
  if (x < m)
    m = x;
  scanf("%d%d", &x, &y);
  if (n < x)
    x = 1;
  else if (n % x != 0)
    x = n / x + 1;
  else
    x = n / x;
  x = x * y;
  if (x < m)
    m = x;
  printf("%d", m);
  return 0;
}