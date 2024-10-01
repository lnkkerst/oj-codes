#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

int n, f[5001][5001], ans;
int v[5001], w[5001];
bool b[5001];

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

void dfs(int step, int wk, int sum) {
  ans = max(ans, sum);
  if (step == n) {
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      if (v[i] - wk < 0) {
        continue;
      }
      b[i] = 1;
      dfs(step + 1, wk + w[i], sum + v[i] - wk);
      b[i] = 0;
    }
  }
}

int main() {
  // freopen("wizard.in", "r", stdin);
  // freopen("wizard.out", "w", stdout);
  n = read();
  for (int i = 1; i <= n; ++i) {
    v[i] = read(), w[i] = read();
  }
  dfs(0, 0, 0);
  print(ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
