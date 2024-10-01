#include <cctype>
#include <cstdio>
#include <unordered_map>
#define int long long
using namespace std;

unordered_map<int, int> b;

typedef long long LL;
#define gc                                                               \
  pa == pb && (pb = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pb) \
    ? EOF                                                                \
    : *pa++
static char buf[100000], *pa(buf), *pb(buf);
inline LL readint() {
  LL x = 0;
  char c = gc;
  while (c < '0' || c > '9') {
    c = gc;
  }
  for (; c >= '0' && c <= '9'; c = gc) {
    x = x * 10 + (c & 15);
  }
  return x;
}

signed main() {
  int n = readint(), k = readint();
  for (int i = 1; i <= n; ++i) {
    int x = readint();
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
