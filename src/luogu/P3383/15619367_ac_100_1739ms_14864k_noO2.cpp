#include <cstdio>
#define MAXN 10000010

int prime[MAXN], cnt = 0;
bool IsNotprime[MAXN];

void sieve() {
  IsNotprime[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    if (!IsNotprime[i]) {
      prime[++cnt] = i;
      for (int j = i * 2; j <= MAXN; j += i) {
        IsNotprime[j] = 1;
      }
    }
  }
}

int main() {
  int n, m;
  sieve();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int t;
    scanf("%d", &t);
    IsNotprime[t] ? printf("No\n") : printf("Yes\n");
  }

  return 0;
}
