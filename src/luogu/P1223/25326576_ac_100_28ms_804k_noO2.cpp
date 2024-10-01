#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  pair<int, int> a[1001];
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    a[i] = make_pair(tmp, i);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    cout << a[i].second << ' ';
  }
  cout << endl;
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += a[i].first * (n - i);
  }
  printf("%.2lf\n", ans / n);
  return 0;
}
