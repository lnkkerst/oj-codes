#include <cstdio>
using namespace std;
int main() {
  int a = 0, k;
  scanf("%d", &k);
  double s, i;
  for (i = 1;; i++) {
    s = s + 1 / i;
    a++;
    if (s > k) {
      printf("%d", a);
      return 0;
    }
  }
}