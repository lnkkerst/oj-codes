#include <cstdio>
using namespace std;
int main() {
  int s1, s2, s3, s[10000] = {0}, b = 0, c = 0;
  scanf("%d%d%d", &s1, &s2, &s3);
  for (int i = 1; i <= s1; i++) {
    for (int j = 1; j <= s2; j++) {
      for (int k = 1; k <= s3; k++) {
        s[i + j + k]++;
      }
    }
  }
  for (int i = 0; i <= 9999; i++) {
    if (s[i] > b) {
      b = s[i];
      c = i;
    }
  }
  printf("%d", c);
  return 0;
}
