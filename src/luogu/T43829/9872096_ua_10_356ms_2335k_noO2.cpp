#include <cmath>
#include <cstdio>
using namespace std;
long long a[100010], t = 0;
void opt1() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (long long i = 0; i < n; i++) {
    a[t] = m;
    t++;
  }
}
void opt2() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 0; i < t; i++) {
    a[i] = a[i + n];
  }
  t = t - n;
}
void opt3() {
  long long l, r, x, c, m;
  scanf("%lld%lld%lld%lld", &l, &r, &x, &c);
  m = r - l + 1;
  m = pow(m, x);
  m %= c;
  for (long long i = l - 1; i < r; i++) {
    a[i] = m;
  }
}
void opt4() {
  long long l, r, max = 0;
  scanf("%lld%lld", &l, &r);
  for (long long i = l - 1; i < r; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  a[l - 1] = max;
  for (long long i = l; i < t; i++) {
    a[i] = a[i + r - l];
  }
  t = t - (r - l);
  printf("%lld\n", max);
}
void opt5() {
  long long l, r;
  scanf("%lld%lld", &l, &r);
  for (int i = l - 1; i < r; i++) {
    a[i] = sqrt(a[i]);
  }
}
int main() {
  long long m, n;
  scanf("%lld", &m);
  for (long long i = 0; i < m; i++) {
    scanf("%lld", &n);
    if (n == 1) {
      opt1();
    } else if (n == 2) {
      opt2();
    } else if (n == 3) {
      opt3();
    } else if (n == 4) {
      opt4();
    } else if (n == 5) {
      opt5();
    }
  }
  for (long long i = 0; i < t; i++) {
    printf("%lld ", a[i]);
  }
  return 0;
}
