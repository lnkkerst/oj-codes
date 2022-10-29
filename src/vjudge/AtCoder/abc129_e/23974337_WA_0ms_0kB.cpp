#include <cstdio>
#include <cstring>

const int MOD = (int)1e9 + 7;
char str[100010];
int ans = 1, len;

int qpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret *= x;
    x *= x, k >>= 1;
  }
  return ret;
}

int main() {
  scanf("%s", str + 1);
  len = strlen(str + 1);
  for (int i = 1; i <= len; ++i)
    if (str[i] == '1')
      ans *= 2, ans += qpow(3, len - i), ans %= MOD;
  printf("%d", ans);
  return 0;
}