#include <bits/stdc++.h>
using namespace std;

unsigned long long n, a[300010];

long double calc(int sum, int i) {
  return (long double)sum * (long double)sum / (long double)i;
}

int main() {
  cin >> n;
  for (unsigned long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<unsigned long long>());
  unsigned long long ans = 1, ans_sum;
  unsigned long long sum = a[1];
  for (unsigned long long i = 2; i <= n; ++i) {
    if ((sum + a[i]) * (sum + a[i]) * (i - 1) > sum * sum * i) {
      sum += a[i], ans = i, ans_sum = sum;
    }
  }
  cout << fixed << setprecision(10) << calc(ans_sum, ans);
  return 0;
}
