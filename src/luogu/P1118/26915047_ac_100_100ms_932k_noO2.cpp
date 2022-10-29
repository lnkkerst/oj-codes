#include <cctype>
#include <cmath>
#include <cstdio>

int n, sum;
bool vis[36];
int ans[36];
int f[36];

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

bool dfs(int step, int num, int k) {
  if (k > sum)
    return 0;
  if (step == n) {
    if (k == sum) {
      ans[step] = num;
      return 1;
    } else
      return 0;
  }
  vis[num] = 1;
  for (int i = 1; i <= n; ++i)
    if (!vis[i] && dfs(step + 1, i, k + f[step] * i)) {
      ans[step] = num;
      return 1;
    }
  vis[num] = 0;
  return 0;
}

int main() {
  n = read(), sum = read();
  f[0] = f[n - 1] = 1;
  for (int i = 1; i * 2 < n; ++i)
    f[i] = f[n - 1 - i] = (n - i) * f[i - 1] / i;
  if (dfs(0, 0, 0))
    for (int i = 1; i <= n; ++i)
      print(ans[i]), putchar(' ');
  return 0;
}