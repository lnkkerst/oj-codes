#include <cstdio>
using namespace std;
int main() {
  int a, b, c, x, y, z;
  scanf("%ld%ld%ld", &a, &b, &c);
  for (int i = 100; i <= 333; i++) {
    x = i;
    y = i * b / a;
    z = i * c / a;
    int l[10], sum = 0, cj = 1;
    l[1] = x / 100;
    l[2] = x / 10 % 10;
    l[3] = x % 10;
    l[4] = y / 100;
    l[5] = y / 10 % 10;
    l[6] = y % 10;
    l[7] = z / 100;
    l[8] = z / 10 % 10;
    l[9] = z % 10;
    for (int j = 1; j <= 9; j++) {
      sum += l[j];
      cj *= l[j];
    }
    if (sum == 45 && cj == 362880)
      printf("%ld %ld %ld\n", x, y, z);
  }
  return 0;
}