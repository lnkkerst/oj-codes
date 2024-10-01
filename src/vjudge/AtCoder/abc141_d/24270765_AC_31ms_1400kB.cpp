#include <cctype>
#include <cstdio>
#include <queue>
#define int long long

std::priority_queue<int> a;
int n, m;

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
    a.push(read());
  }
  while (m--) {
    int t = a.top();
    a.pop();
    a.push(t >> 1);
  }
  int ans = 0;
  while (!a.empty()) {
    ans += a.top(), a.pop();
  }
  print(ans);
  return 0;
}
