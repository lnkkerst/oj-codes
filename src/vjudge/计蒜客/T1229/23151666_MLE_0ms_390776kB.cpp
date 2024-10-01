#include <cctype>
#include <cstdio>

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

int a[100000010];
char opt[4];

int max(int x, int y) {
  return x > y ? x : y;
};

int main() {
  int n = read();
  while (n--) {
    scanf("%s", opt + 1);
    int x = read();
    if (opt[1] == 'a' && opt[2] == 'd') {
      a[x] = max(a[x] + 1, 1), print(a[x]), putchar('\n');
    }
    if (opt[1] == 'd') {
      print(a[x]), putchar('\n'), a[x] = -1;
    } else {
      print(a[x] ? 1 : 0), putchar(' '), print(max(a[x], 0)), putchar('\n');
    }
  }
  return 0;
}
