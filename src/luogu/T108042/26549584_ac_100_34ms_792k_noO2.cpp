#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

struct Qus {
  int a, b;
} q[100010];

int n, maxa, maxn, r;
int ans[100010];

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

bool cmp(Qus a, Qus b) {
  int sizea = abs(a.a - a.b), sizeb = abs(b.a - b.b);
  return sizea == sizeb ? a.a < b.a : sizea > sizeb;
}

int main() {
  // freopen("tallest.in", "r", stdin);
  // freopen("tallest.out", "w", stdout);
  n = read(), maxa = read(), maxn = read(), r = read();
  ans[maxa] = maxn;
  for (int i = 1; i <= r; ++i) {
    q[i].a = read(), q[i].b = read();
  }
  sort(q + 1, q + n + 1, cmp);
  // for(int i = 1; i <= r; ++i) printf("%d %d\n", q[i].a, q[i].b);
  // for(int i = 1; i <= r; ++i) {
  //     int na = q[i].a, nb = q[i].b;
  //     printf("%d %d\n", na, nb);
  //     if(na > nb) {
  //         if(!ans[na]) {
  //             ans[na] = maxn, ans[nb] = maxn;
  //             for(int j = nb + 1; j <= na - 1; ++j) ans[j] = ans[na] - 1;
  //         }
  //         else {
  //             for(int j = nb + 1; j <= na - 1; ++j)
  //                 if((ans[j] > ans[na] - 1) || !ans[j]) ans[j] = ans[na] -
  //                 1;
  //         }
  //     }
  //     else {
  //         swap(na, nb);
  //         if(!ans[nb]) {
  //             ans[nb] = maxn, ans[na] = maxn;
  //             printf("%d %d\n", ans[nb], ans[na]);
  //             for(int j = nb + 1; j <= na - 1; ++j) ans[j] = ans[nb] - 1;
  //         }
  //         else {
  //             for(int j = nb + 1; j <= na - 1; ++j)
  //                 if((ans[j] > ans[nb - 1]) || !ans[j]) ans[j] = ans[nb] -
  //                 1;
  //         }
  //     }
  //     for(int i = 1; i <= n; ++i) print(ans[i]), putchar(' ');
  //     putchar('\n');
  // }
  for (int i = 1; i <= r; ++i) {
    int na = q[i].a, nb = q[i].b;
    if (na > nb) {
      if (!ans[na] && !ans[nb]) {
        ans[na] = ans[nb] = maxn;
        for (int j = nb + 1; j <= na - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      } else if (ans[nb] && !ans[na]) {
        ans[na] = ans[nb];
        for (int j = nb + 1; j <= na - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      } else if (!ans[nb] && ans[na]) {
        ans[nb] = maxn;
        for (int j = nb + 1; j <= na - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      } else {
        for (int j = nb + 1; j <= na - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      }
    } else {
      if (!ans[na] && !ans[nb]) {
        ans[na] = ans[nb] = maxn;
        for (int j = na + 1; j <= nb - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      }
      if (!ans[na] && ans[nb]) {
        ans[na] = ans[nb];
        for (int j = na + 1; j <= nb - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      }
      if (ans[na] && !ans[nb]) {
        ans[nb] = maxn;
        for (int j = na + 1; j <= nb - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      } else {
        for (int j = na + 1; j <= nb - 1; ++j) {
          if ((ans[j] > ans[na] - 1) || !ans[j]) {
            ans[j] = ans[na] - 1;
          }
        }
      }
    }
    // for(int i = 1; i <= n; ++i) print(ans[i]), putchar(' ');
    // putchar('\n');
  }
  for (int i = 1; i <= n; ++i) {
    if (!ans[i]) {
      print(maxn), putchar('\n');
    } else {
      print(ans[i]), putchar('\n');
    }
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
