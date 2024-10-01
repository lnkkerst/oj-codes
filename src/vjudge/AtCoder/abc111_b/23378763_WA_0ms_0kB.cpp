#include <cstdio>

bool pd(int x) {
  if (x % 10 == x / 10 % 10 && x % 10 == x / 100) {
    return 1;
  }
  return 0;
}

int main() {
  int x;
  scanf("%d", &x);
  while (!pd(++x))
    ;
  printf("%d", x);
  return 0;
}
