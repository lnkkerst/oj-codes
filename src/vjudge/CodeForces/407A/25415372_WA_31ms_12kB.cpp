#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i < a; ++i) {
    for (int j = 1; j < b; ++j) {
      if (i == j)
        continue;
      int l1 = sqrt(a * a - i * i);
      int l2 = sqrt(b * b - j * j);
      if (i * j == l1 * l2) {
        printf("YES\n0 0\n%d %d\n%d %d", -l1, i, l2, j);
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}