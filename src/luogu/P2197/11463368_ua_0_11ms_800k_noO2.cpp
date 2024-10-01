#include <cstdio>

int main() {
  freopen("in", "r", stdin);
  int n, num, i, j, t;
  scanf("%d", &n);
  const int N = n;
  int ans[N];
  for (i = 0; i < n; i++) {
    ans[i] = 0;
    scanf("%d", &t);
    for (j = 0; j < t; j++) {
      scanf("%d", &num);
      ans[i] = ans[i] ^ num;
    }
  }
  for (i = 0; i < n; i++) {
    if (ans[i] == 0) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
  return 0;
}
