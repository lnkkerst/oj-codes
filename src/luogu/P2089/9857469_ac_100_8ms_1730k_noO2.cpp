#include <cstdio>
using namespace std;
int main() {
  int n, s = 0;
  scanf("%d", &n);
  for (int a = 1; a <= 3; a++) {
    for (int b = 1; b <= 3; b++) {
      for (int c = 1; c <= 3; c++) {
        for (int d = 1; d <= 3; d++) {
          for (int e = 1; e <= 3; e++) {
            for (int f = 1; f <= 3; f++) {
              for (int g = 1; g <= 3; g++) {
                for (int h = 1; h <= 3; h++) {
                  for (int i = 1; i <= 3; i++) {
                    for (int j = 1; j <= 3; j++) {
                      if (a + b + c + d + e + f + g + h + i + j == n) {
                        s++;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%d\n", s);
  for (int a = 1; a <= 3; a++) {
    for (int b = 1; b <= 3; b++) {
      for (int c = 1; c <= 3; c++) {
        for (int d = 1; d <= 3; d++) {
          for (int e = 1; e <= 3; e++) {
            for (int f = 1; f <= 3; f++) {
              for (int g = 1; g <= 3; g++) {
                for (int h = 1; h <= 3; h++) {
                  for (int i = 1; i <= 3; i++) {
                    for (int j = 1; j <= 3; j++) {
                      if (a + b + c + d + e + f + g + h + i + j == n) {
                        printf("%d %d %d %d %d %d %d "
                               "%d %d %d\n",
                               a, b, c, d, e, f, g, h, i, j);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
