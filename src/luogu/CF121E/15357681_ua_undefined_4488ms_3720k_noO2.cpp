#include <cstdio>
#define lowbit(x) x & -x

long long tree[500005];
int n, m;

void add(int x, long long num) {
  while (x <= n) {
    tree[x] += num;
    x += lowbit(x);
  }
}

long long query(int x) {
  long long ans = 0;
  while (x) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}

bool pd(int x) {
  while (x != 0) {
    if (x % 10 != 4 && x % 10 != 7) {
      return 0;
    }

    x /= 10;
  }
  return 1;
}

int main() {

  scanf("%d%d", &n, &m);
  long long last = 0, now;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &now);
    add(i, now - last);
    last = now;
  }
  char flg[6];
  while (m--) {
    scanf("%s", flg);
    if (flg[0] == 'a') {
      int x, y;
      long long k;
      scanf("%d%d%lld", &x, &y, &k);
      add(x, k);
      add(y + 1, -k);
    } else {
      int ll, rr, anss = 0;
      scanf("%d%d", &ll, &rr);
      for (int i = ll; i <= rr; i++) {
        anss += pd(query(i));
      }
      printf("%d\n", anss);
    }
  }
  return 0;
}
