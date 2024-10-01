#include <bits/stdc++.h>
using namespace std;

int a, b, m;
int ar[1000001], t[1000001];

int main() {
  cin >> a >> b >> m;
  for (int i = 2; i <= b; ++i) {
    ar[i] = (ar[i - 1] + m) % i;
  }
  for (int i = a; i <= b; ++i) {
    ++t[++ar[i]];
  }
  int ans = *max_element(t + 1, t + b + 1);
  cout << ans << endl;
  for (int i = 1; i <= b; ++i) {
    if (t[i] == ans) {
      cout << i << ' ';
    }
  }
  return 0;
}
