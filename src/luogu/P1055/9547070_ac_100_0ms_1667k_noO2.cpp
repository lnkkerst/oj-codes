#include <cstdio>
using namespace std;
int main() {
  char a[13];
  int n, b[13];
  for (int i = 0; i < 13; i++) {
    a[i] = getchar();
  }
  for (int i = 0; i < 13; i++) {
    b[i] = a[i] - 48;
  }
  n = (b[0] * 1 + b[2] * 2 + b[3] * 3 + b[4] * 4 + b[6] * 5 + b[7] * 6 +
       b[8] * 7 + b[9] * 8 + b[10] * 9) %
      11;
  if (n == 10) {
    if (a[12] == 'X')
      printf("Right");
    else {
      for (int i = 0; i < 12; i++)
        printf("%c", a[i]);
      printf("X");
    }
  } else {
    if (b[12] == n)
      printf("Right");
    else {
      for (int i = 0; i < 12; i++)
        printf("%c", a[i]);
      printf("%d", n);
    }
  }
  return 0;
}