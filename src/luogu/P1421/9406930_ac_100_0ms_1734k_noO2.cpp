#include <cstdio>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  a = a * 10 + b;
  b = a / 19;
  printf("%d", b);
  return 0;
}
