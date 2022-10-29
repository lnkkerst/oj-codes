#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, s, a[23], b[23] = {1}, ans = 0;

int main() {
  for (int i = 1; i <= 12; ++i)
    b[i] = b[i - 1] * i;
  while (cin >> n >> s) {
    if (!n && !s)
      return 0;
    ans = 0;
    for (int i = 0; i < 10; ++i)
      a[i] = i;
    do {
      int sum = 0;
      for (int i = 0; i < n; ++i)
        sum += a[i];
      if (sum == s)
        ++ans;
    } while (next_permutation(a, a + 10));
    cout << ans / b[n] / b[10 - n] << endl;
  }
  return 0;
}