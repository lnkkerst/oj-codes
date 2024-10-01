#include <cstdio>
using namespace std;
int main() {
  int n, a[24] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 8, 4, 7}, s = 0;
  scanf("%d", &n);
  n = n - 4;
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 13; j++) {
      for (int k = 0; k < 13; k++) {
        if (i + j == k && a[i] + a[j] + a[k] == n) {
          s++;
        }
      }
    }
  }
  printf("%d", s);
  return 0;
}
