#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int a[3];
  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  sort(a, a + 3);
  for (int i = a[2] / 2; i >= 1; i--) {
    if (a[0] % i == 0 && a[2] % i == 0) {
      a[0] /= i;
      a[2] /= i;
    }
  }
  printf("%d/%d", a[0], a[2]);
  return 0;
}