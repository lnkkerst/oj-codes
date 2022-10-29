#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int MOD = (int)1e9 + 7;

int n, k;

int exgcd(int a, int b, int &x, int &y) {
  if (b == 0)
    return x = 1, y = 0, a;
  int r = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return r;
}

int calc(int a, int b) {
  int x, y;
  exgcd(b, MOD, x, y);
  x *= a;
  x = (x % MOD + MOD) % MOD;
  return x;
}

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

int qpow(int x, int mi) {
  int ret = 1, tmp = x;
  while (mi) {
    if (mi & 1)
      ret *= tmp, ret %= MOD;
    tmp *= tmp, tmp %= MOD;
    mi >>= 1;
  }
  return ret % MOD;
}

int inv(int x) { return qpow(x, MOD - 2); }

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

signed main() {
  //	freopen("kasrra.in", "r", stdin);
  //	freopen("kasrra.out", "w", stdout);
  n = read(), k = read();
  int t = qpow(n - 1, k - 1);
  int up = k & 1 ? (-1 + t) : (1 + t), down = n * t;
  // int gcdn = gcd(up, down);
  // up /= gcdn, down /= gcdn;
  print((up * inv(down)) % MOD);
  //	fclose(stdin);
  //	fclose(stdout);
  return 0;
}