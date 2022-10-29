#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  bool fl = false;
  for (int i = 0; i < n - 1; ++i) {
    int c1 = 0, c2 = 0;
    for (int j = 0; j <= i; ++j)
      c1 += a[j];
    for (int j = i + 1; j < n; ++j)
      c2 += a[j];
    if (c1 == c2)
      fl = true;
  }
  if (fl)
    puts("Yes");
  else
    puts("No");
  return 0;
}