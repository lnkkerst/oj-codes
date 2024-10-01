#include <cstdio>
using namespace std;
int main() {
  double s, x, v = 7, st = 0;
  scanf("%lf%lf", &s, &x);
  for (;;) {
    st += v;
    v *= 0.98;
    if (st >= s - x && st + v * 0.98 <= s + x) {
      printf("y");
      return 0;
    }
    if (st >= s - x && st + v * 0.98 > s + x) {
      printf("n");
      return 0;
    }
  }
}
