#include <cctype>
#include <cstdio>

int n, k, ans;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

void dfs(int last, int sum, int num) {
  if (num == k) {
    if (sum == n)
      ++ans;
    return;
  }
  for (int i = last; i <= n; ++i)
    dfs(i, sum + i, num + 1);
}

int main() {
  n = read(), k = read();
  dfs(1, 0, 0);
  print(ans);
  return 0;
}