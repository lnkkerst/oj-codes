#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  cin >> a[0];
  a[0] = a[0] ? 1 : -1;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    if (x)
      a[i] = a[i - 1] + 1;
    else
      a[i] = a[i - 1] - 1;
  }
  int ans = -1;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (a[j] - a[i - 1] == 0)
        ans = max(j - i + 1, ans);
  cout << ans;
  return 0;
}