#include <cstdio>
using namespace std;
int main() {
  int h1, m1, s1, h2, m2, s2, n;
  long long s;
  scanf("%ld:%ld:%ld%ld:%ld:%ld%ld", &h1, &m1, &s1, &h2, &m2, &s2, &n);
  if (s2 < s1) {
    s2 = s2 + 60;
    m2--;
  }
  if (m2 < m1) {
    m2 = m2 + 60;
    h2--;
  }
  s = s2 - s1;
  s = s + (m2 - m1) * 60;
  s = s + (h2 - h1) * 3600;
  s = s * n;
  printf("%lld", s);
  return 0;
}