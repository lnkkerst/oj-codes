#include <iostream>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  cout << abs((n - 2) * (m - 2)) << endl;
  return 0;
}