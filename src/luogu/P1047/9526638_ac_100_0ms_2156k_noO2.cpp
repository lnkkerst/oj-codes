#include <cstring>
#include <iostream>
using namespace std;
int l, m;
int sum = 0;
int a[10005];
int main() {
  memset(a, 0, sizeof(a));
  cin >> l >> m;
  for (int i = 1; i <= m; i++) {
    int s, e;
    cin >> s >> e;
    for (int j = s; j <= e; j++) {
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
