#include <cstdio>
using namespace std;
int main() {
  int k, i = 0;
  float s = 0;
  scanf("%d", &k);
  for (;;) {
    if (s > k) {
      printf("%d", i);
      break;
    }
    i++;
    s = s + 1.0 / i;
  }
  return 0;
}
