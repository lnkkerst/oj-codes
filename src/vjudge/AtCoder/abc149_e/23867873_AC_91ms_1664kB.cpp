#include <algorithm>
#include <cctype>
#include <cstdio>
#define int long long

int n, m;
int a[100010], fs[100010];
int l = 0, r = 200010, ans, cnt, res;

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

signed main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    fs[i] = fs[i - 1] + a[i];
  }
  while (l <= r) {
    int mid = (l + r) >> 1;
    cnt = res = 0;
    for (int i = 1; i <= n; ++i) {
      int pos = std::lower_bound(a + 1, a + n + 1, mid - a[i]) - a;
      res += fs[n] - fs[pos - 1] + a[i] * (n - pos + 1);
      cnt += n - pos + 1;
    }
    if (cnt >= m) {
      ans = mid, l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  print(res - ans * (cnt - m));
  return 0;
}
