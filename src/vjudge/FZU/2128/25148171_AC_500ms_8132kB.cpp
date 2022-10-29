#include <algorithm>
#include <cstdio>

struct Node {
  int l, r;
  bool operator<(const Node &b) const {
    if (this->l == b.l)
      return this->r < b.r;
    return this->l < b.l;
  }
};

Node q[1000010];
int kmp[233], n, cnt = 0;
char a[100010], b[233];

int mstrlen(char s[]) {
  int ret = -1;
  while (s[++ret])
    ;
  return ret;
}

void ckmp() {
  kmp[0] = kmp[1] = kmp[2] = 0;
  int la = mstrlen(a + 1), lb = mstrlen(b + 1), j = 0;
  for (int i = 2; i <= lb; ++i) {
    while (j && b[i] != b[j + 1])
      j = kmp[j];
    if (b[j + 1] == b[i])
      ++j;
    kmp[i] = j;
  }
  j = 0;
  for (int i = 1; i <= la; ++i) {
    while (j > 0 && b[j + 1] != a[i])
      j = kmp[j];
    if (b[j + 1] == a[i])
      ++j;
    if (j == lb) {
      q[++cnt] = (Node){i - lb + 1, i};
      j = kmp[j];
    }
  }
}

int max(int x, int y) { return x > y ? x : y; }

int main() {
  while (~scanf("%s%d", a + 1, &n)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%s", b + 1);
      ckmp();
    }
    std::sort(q + 1, q + cnt + 1);
    int ans = -1;
    for (int i = 2; i <= cnt; ++i)
      ans = max(ans, q[i].r - q[i - 1].l - 1);
    if (ans == -1)
      printf("%d\n", mstrlen(a + 1));
    else
      printf("%d\n", ans);
    cnt = 0;
  }
  return 0;
}