#include <cstdio>

double a, b, t;

int main() {
  scanf("%lf%lf%lf", &a, &b, &t);
  printf("%d", (int)((int)((t + 0.5) / a) * b));
  return 0;
}