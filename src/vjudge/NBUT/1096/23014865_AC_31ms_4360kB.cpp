#include <cctype>
#include <cstdio>

int f[1000010] = {0, 1};
int maxn = 1;

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

void init(int x) {
  if (f[maxn] > x) {
    return;
  }
  while (f[maxn] <= x) {
    f[++maxn] = (maxn * maxn + maxn) / 2;
  }
  return;
}

int find(int x) {
  int l = 1, r = maxn;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (f[mid] > x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

void work(int x) {
  init(x);
  int pos = find(x) - 1;
  while (233) {
    if ((x - f[pos]) % pos == 0) {
      print((x - f[pos]) / pos + 1), putchar(' '), print(pos), putchar('\n');
      return;
    }
    --pos;
  }
}

int main() {
  int x;
  while (scanf("%d", &x) != EOF) {
    work(x);
  }
  return 0;
}
