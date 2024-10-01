#include <cstdio>
using namespace std;
int main() {
  int n, x, a = 0;
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j > 0; j = j / 10) {
      if (j % 10 == x) {
        a++;
      }
    }
  }
  printf("%d", a);
  return 0;
}
