#include <cstdio>
using namespace std;
int main() {
  int s = 0, h, a[10];
  for (int i = 0; i < 10; i++)
    scanf("%d", &a[i]);
  scanf("%d", &h);
  h += 30;
  for (int i = 0; i < 10; i++)
    if (a[i] <= h)
      s++;
  printf("%d", s);
  return 0;
}