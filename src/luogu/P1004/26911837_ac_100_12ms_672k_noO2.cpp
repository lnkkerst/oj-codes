#include <cctype>
#include <cstdio>

int e[10][10];
int f[10][10][10][10];
int n;

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

int main() {
  n = read();
  while (233) {
    int x = read(), y = read(), w = read();
    if (!x && !y && !w) {
      break;
    }
    e[x][y] = w;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        int l = i + j - k;
        if (l <= 0) {
          break;
        }
        f[i][j][k][l]
          = max(f[i - 1][j][k - 1][l],
                max(f[i - 1][j][k][l - 1],
                    max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])));
        if (i == k && j == l) {
          f[i][j][k][l] += e[i][j];
        } else {
          f[i][j][k][l] += e[i][j] + e[k][l];
        }
      }
    }
  }
  print(f[n][n][n][n]);
  return 0;
}
