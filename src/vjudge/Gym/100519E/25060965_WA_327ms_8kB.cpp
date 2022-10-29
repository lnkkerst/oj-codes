#include <cmath>
#include <iostream>
#define int long long
using namespace std;

int n, d, k, ansn, ansk = 2;

int solve(int k, int num) {
  int t = n, ret = 0;
  while (t) {
    if (t % k == num)
      ++ret;
    else
      return ret;
    t /= k;
  }
  return ret;
}

signed main() {
  cin >> n >> d;
  for (int i = 2; i <= 50000000; ++i) {
    int tmp = solve(i, d);
    if (tmp > ansn)
      ansn = tmp, ansk = i;
  }
  cout << ansk << ' ' << ansn << endl;
  return 0;
}