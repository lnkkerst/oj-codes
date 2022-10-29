#include <iomanip>
#include <iostream>
#define int long long
using namespace std;

signed main() {
  int n;
  cin >> n;
  cout << (n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4);
  return 0;
}