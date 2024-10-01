#include <iostream>
using namespace std;
int main() {
  int n, s = 1, max = 0;
  cin >> n;
  const int N = n;
  int a[N];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1] + 1) {
      s++;
    } else {
      s = 1;
    }
    if (s > max) {
      max = s;
    }
  }
  cout << max;
  return 0;
}
