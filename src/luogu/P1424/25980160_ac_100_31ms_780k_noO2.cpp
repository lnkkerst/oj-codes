#include <cstdio>
using namespace std;
int main() {
  int x, n, s = 0;
  scanf("%d%d", &x, &n);
  for (int i = 1; i <= n; i++) {
    if (x == 8)
      x = 1;
    if (x != 6 && x != 7)
      s = s + 250;
    x++;
  }
  printf("%d", s);
  return 0;
}