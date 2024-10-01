#include <cstdio>
using namespace std;
int main() {
  int c1, c2, x = 0, w = 0;
  for (int i = 1; i <= 7; i++) {
    scanf("%d%d", &c1, &c2);
    if (c1 + c2 > 8 && c1 + c2 > x) {
      w = i;
      x = c1 + c2;
    }
  }
  printf("%d", w);
  return 0;
}
