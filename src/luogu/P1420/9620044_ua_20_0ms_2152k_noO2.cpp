#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, s = 1, e = 0;
  cin >> n;
  const int N = n;
  int a[N];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1] + 1) {
      s++;
    } else {
      if (s > e) {
        e = s;
        s = 1;
      }
    }
  }
  if (e == 0) {
    cout << s;
  } else {
    cout << e;
  }
  return 0;
}
