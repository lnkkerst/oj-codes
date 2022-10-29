#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int l, m, sum = 0;
  cin >> l >> m;
  const int L = l + 10;
  int a[L];
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= m; i++) {
    int s, e;
    cin >> s >> e;
    for (int j = s; j <= e; j++) {
      if (a[i] == 0)
        a[j] = 1;
    }
  }
  for (int i = 0; i <= l; i++) {
    if (a[i] == 0) {
      sum++;
    }
  }
  cout << sum;
  return 0;
}