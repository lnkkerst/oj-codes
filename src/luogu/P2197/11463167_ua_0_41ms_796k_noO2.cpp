#include <cstdio>

int main() {
  int n, num, i, j, t;
  scanf("%d", &n);
  const int N = n;
  bool ans[N];
  for (i = 0; i < n; i++) {
    ans[i] = 0;
    scanf("%d", &t);
    for (j = 0; j < t; j++) {
      scanf("%d", &num);
      ans[i] = ans[i] ^ num;
    }
  }
  for (i = 0; i < n; i++)
    if (ans[i] == 0)
      printf("No\n");
    else
      printf("Yes\n");
  return 0;
}