#include <cstdio>
using namespace std;
int main() {
  int n, b[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, a[1001] = {6}, s = 0;
  for (int i = 1, j; i <= 1000; i++) {
    j = i;
    while (j >= 1) {
      a[i] = a[i] + b[j % 10];
      j = j / 10;
    }
  }
  scanf("%d", &n);
  n = n - 4;
  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (a[i] + a[j] + a[i + j] == n) {
        s++;
      }
    }
  }
  printf("%d", s);
}
