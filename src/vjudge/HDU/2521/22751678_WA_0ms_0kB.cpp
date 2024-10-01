#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int prime[] = {1,   2,   4,   6,   12,  24,   36,   48,   60,  120,
               180, 240, 360, 720, 840, 1260, 1680, 2520, 5040};

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

int main() {
  int n = read();
  while (n--) {
    int l = read(), r = read(), i = 18;
    while (233) {
      if (prime[i] < r) {
        print(prime[i]), putchar('\n');
        break;
      } else {
        --i;
      }
    }
  }
  return 0;
}
