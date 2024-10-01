#include <cstdio>

int a, m, phi = 1;
int bm, flag;

int pow(int x, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

int main() {
  scanf("%d%d", &a, &m);
  a %= m;
  int mm = m;
  for (int i = 2; i * i <= mm; ++i) {
    if (mm % i) {
      continue;
    }
    phi *= i - 1;
    mm /= i;
    while (mm % i == 0) {
      phi *= i, mm /= i;
    }
  }
  if (mm > 1) {
    phi *= mm - 1;
  }
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  while (bm = bm * 10ll + (ch ^ '0'), (ch = getchar()) >= '0' && ch <= '9') {
    if (bm >= phi) {
      flag = 1, bm %= phi;
    }
  }

  if (bm >= phi) {
    flag = 1;
    bm %= phi;
  }
  if (flag) {
    bm += phi;
  }
  printf("%d", pow(a, bm));

  return 0;
}
