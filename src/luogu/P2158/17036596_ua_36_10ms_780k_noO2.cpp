#include <cctype>
#include <cstdio>
#include <vector>
#define num ch - '0'
#define MAXN 40010

std::vector<int> a, b;
std::vector<bool> vis;
int n, x;

int read() {
  int res;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (res = num; isdigit(ch = getchar()); res = res * 10 + num)
    (flag) && (res = -res);
  return res;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }

  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  vis.resize(MAXN, 0);
  b.push_back(0);
  a.push_back(1);
  a.push_back(1);
  n = read() - 1;
  if (n == 0)
    print(0);
  else {
    for (int i = 2; i <= n; ++i) {
      if (!vis[i]) {
        b.push_back(i);
        a[i] = i - 1;
      }
      for (int j = 1; (x = i * b[j]) <= n; ++j) {
        vis[x] = 1;
        if (i % b[j])
          a[x] = a[i] * (b[j] - 1);
        else {
          a[x] = a[i] * b[j];
          break;
        }
      }
      a[i] += a[i - 1];
    }
    print(a[n] << 1 | 1);
  }
  return 0;
}