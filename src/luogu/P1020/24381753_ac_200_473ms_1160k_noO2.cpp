#include <bits/stdc++.h>

using namespace std;

int n, l1, l2;
int a[100010], d1[100010], d2[100010];

int main() {
  while (cin >> a[++n])
    ;
  --n;
  l1 = l2 = 1;
  d1[1] = d2[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    if (d1[l1] >= a[i]) {
      d1[++l1] = a[i];
    } else {
      *upper_bound(d1 + 1, d1 + l1 + 1, a[i], greater<int>()) = a[i];
    }
    if (d2[l2] < a[i]) {
      d2[++l2] = a[i];
    } else {
      *lower_bound(d2 + 1, d2 + l2 + 1, a[i]) = a[i];
    }
  }
  cout << l1 << endl << l2 << endl;
  return 0;
}
