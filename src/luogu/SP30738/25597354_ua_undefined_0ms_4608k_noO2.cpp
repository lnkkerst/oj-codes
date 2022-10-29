#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100010];
bitset<100010> b;

int main() {
  cin >> n >> q;
  b[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    b |= b << tmp;
  }
  for (int i = 1; i < 100010; ++i)
    a[i] = a[i - 1] + b[i];
  for (int i = 1; i <= q; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    cout << (a[t2] - a[t1 - 1]) << endl;
  }
  return 0;
}