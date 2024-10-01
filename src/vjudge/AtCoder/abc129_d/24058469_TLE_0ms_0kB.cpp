#include <cctype>
#include <cstdio>

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m, ans = -1;
bool a[2333][2333];

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

int max(int x, int y) {
  return x > y ? x : y;
}

int solve(int x, int y) {
  int ret = 1, tx, ty;
  for (int i = 0; i < 4; ++i) {
    tx = x + dx[i], ty = y + dy[i];
    while (a[tx][ty] && tx <= n && tx >= 1 && ty <= m && ty >= 1) {
      ++ret, tx += dx[i], ty += dy[i];
    }
  }
  return ret;
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch = getchar();
      while (ch != '#' && ch != '.') {
        ch = getchar();
      }
      a[i][j] = ch == '.';
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        ans = max(ans, solve(i, j));
      }
    }
  }
  return print(ans), 0;
}
