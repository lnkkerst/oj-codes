#include <cstdio>
using namespace std;
int check(int a, int n) {
  int mid, b = n;
  while (a < b) {
    mid = (a + b) / 2;
    if (mid * (mid + 1) / 2 < n) {
      a = mid + 1;
    } else {
      b = mid;
    }
  }
  return a;
}
int main() {
  int n, l = 1, s;
  scanf("%ld", &n);
  l = check(l, n);
  s = n - l * (l - 1) / 2;
  if (l % 2 == 0) {
    printf("%ld/%ld", s, l + 1 - s);
  } else {
    printf("%ld/%ld", l + 1 - s, s);
  }
  return 0;
}
