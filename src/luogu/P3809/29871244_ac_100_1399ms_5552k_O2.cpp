#include <algorithm>
#include <cstdio>
#include <cstring>

char str[1000010];
int rk[1000010];

bool cmp(int a, int b) {
  return strcmp(&str[a], &str[b]) > 0 ? false : true;
}

int main() {
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    rk[i] = i;
  }
  std::sort(rk + 0, rk + len, cmp);
  for (int i = 0; i < len; ++i) {
    printf("%d ", rk[i] + 1);
  }
  return 0;
}
