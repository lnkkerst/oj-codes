#include <cstdio>
using namespace std;
int main() {
  int a[10], b[42] = {0}, s = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &a[i]);
    b[a[i] % 42]++;
  }
  for (int i = 0; i < 42; i++) {
    if (b[i] != 0) {
      s++;
    }
  }
  printf("%d", s);
  return 0;
}
