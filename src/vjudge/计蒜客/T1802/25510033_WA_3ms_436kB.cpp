#include <algorithm>
#include <iostream>
#define int long long
using namespace std;

bool pd(int x, int b) {
  string s;
  while (x) {
    s.push_back(x % b);
    x /= b;
  }
  string re = s;
  reverse(re.begin(), re.end());
  return re == s;
}

signed main() {
  int b;
  cin >> b;
  for (int i = 1; i <= 300; ++i) {
    if (pd(i * i, b)) {
      cout << i << ' ' << i * i << endl;
    }
  }
  return 0;
}