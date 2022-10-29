// luogu-judger-enable-o2
#include <cstdio>
using namespace std;
int main() {
  short a, b, c, x, y, z, t;
  scanf("%d:%d:%d%d:%d:%d%ld", &a, &b, &c, &x, &y, &z, &t);
  printf("%lld", ((x - a) * 3600 + (y - b) * 60 + (z - c)) * t);
  return 0;
}