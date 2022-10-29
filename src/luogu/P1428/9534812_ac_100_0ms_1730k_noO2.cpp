#include <cstdio>
using namespace std;
int main() {
  int n, s;
  scanf("%d", &n);
  const int N = n;
  int a[N];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("0 ");
  for (int i = 1; i < n; i++) {
    s = 0;
    for (int j = 1; j <= i; j++) {
      if (a[i - j] < a[i])
        s++;
    }
    printf("%d ", s);
  }
  return 0;
}