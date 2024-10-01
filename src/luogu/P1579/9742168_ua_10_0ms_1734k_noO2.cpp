#include <cmath>
#include <cstdio>
using namespace std;
bool pd(int x) {
  if (x % 2 == 0) {
    return 0;
  }
  for (int i = 9; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int n, flag = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n - 4; i++) {
    if (flag == 1) {
      break;
    }
    for (int j = 2; j <= n - 4; j++) {
      int k = n - i - j;
      if (pd(i) == 1 && pd(j) == 1 && pd(k) == 1 && k > 1) {
        printf("%d %d %d", i, j, k);
        flag = 1;
        break;
      }
    }
  }
}
