#include <cstdio>
using namespace std;
int main() {
  int a[10], b[41] = {0}, s = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &a[i]);
    b[a[i] % 42]++;
  }
  for (int i = 0; i < 41; i++) {
    if (b[i] != 0)
      s++;
  }
  printf("%d", s);
  return 0;
}