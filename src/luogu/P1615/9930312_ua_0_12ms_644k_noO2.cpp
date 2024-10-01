#include <cstdio>
using namespace std;
int main() {
  int h1, m1, s1, h2, m2, s2, n;
  long long s;
  scanf("%ld:%ld:%ld%ld:%ld:%ld%ld", &h1, &m1, &s1, &h2, &m2, &s2, &n);
  s = ((h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1)) * n;
  printf("%lld", s);
  return 0;
}
