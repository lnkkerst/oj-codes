#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, k;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int pos = min_element(a + 1, a + n + 1) - a;
  cout << (n - 1 + k - 2) / (k - 1);
  return 0;
}