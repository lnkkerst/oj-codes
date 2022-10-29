#include <iostream>
using namespace std;
int main() {
  long long x, n, s = 1;
  cin >> x >> n;
  for (int i = 1; i <= n; i++)
    s += s * x;
  cout << s;
  return 0;
}