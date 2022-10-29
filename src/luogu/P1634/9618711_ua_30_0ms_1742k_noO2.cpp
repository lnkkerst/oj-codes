#include <cstdio>
using namespace std;
int main() {
  int x, n, s = 1;
  scanf("%d%d", &x, &n);
  for (int i = 1; i <= n; i++)
    s += s * x;
  printf("%d", s);
  return 0;
}