#include <cctype>
#include <cstdio>
#include <unordered_map>
#define int long long
using namespace std;

unordered_map<int, int> b;

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (fl = -1);
  }
  ret = ch - '0';
  while (isdigit(ch = getchar())) {
    ret *= 10, ret += ch - '0';
  }
  return ret * fl;
}
signed main() {
  int n = read(), k = read();
  for (int i = 1; i <= n; ++i) {
    int x = read();
    auto cnt = b.find(x);
    if (cnt != b.end() && !((cnt->second + 1) % k)) {
      b.erase(cnt);
    } else {
      ++b[x];
    }
  }

  for (auto i : b) {
    if (i.second % k) {
      printf("%lld", i.first);
      break;
    }
  }
  return 0;
}
