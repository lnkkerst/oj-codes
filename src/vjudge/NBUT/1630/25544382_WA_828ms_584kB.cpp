#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i)
      cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < (int)a.size(); ++i)
      ans += a[i] * b[i];
    cout << ans << endl;
  }
  return 0;
}