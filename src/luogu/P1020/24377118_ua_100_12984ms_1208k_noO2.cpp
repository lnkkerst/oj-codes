#include <bits/stdc++.h>

using namespace std;

int n, m;
int f[100010], a[100010];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int read() {
  int ret;
  char ch;
  bool f = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return f ? -ret : ret;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  while (cin >> a[++n])
    ;
  --n;
  int ans = -1;
  for (int i = n; i >= 1; --i) {
    f[i] = 1;
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] <= a[i]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
    ans = max(f[i], ans);
  }
  print(ans);
  putchar('\n');
  ans = -1;
  for (int i = n; i >= 1; --i) {
    f[i] = 1;
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] > a[i]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
    ans = max(ans, f[i]);
  }
  print(ans);
  return 0;
}
