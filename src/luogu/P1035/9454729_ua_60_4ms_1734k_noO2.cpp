#include <cstdio>
using namespace std;
int main() {
  int k, i;
  float s = 0;
  scanf("%d", &k);
  for (i = 1; s <= k; i++) {
    s = s + 1.0 / i;
  }
  printf("%d", i - 1);
  return 0;
}