#include <algorithm>
#include <iostream>
using namespace std;

int a[10], b[10] = {1, 1};

int main() {
  int n, s;
  for (int i = 1; i < 10; ++i)
    b[i] = i * b[i - 1];
  while (cin >> n >> s) {
    if (!n || !s)
      return 0;
    for (int i = 0; i <= 9; ++i)
      a[i] = i;
    int ans = 0;
    do {
      int sum = 0;
      for (int i = 0; i < n; ++i)
        sum += a[i];
      if (sum == s)
        ++ans;
    } while (next_permutation(a, a + 10));
    cout << ans / b[10 - n] / b[n] << endl;
  }
}