#include <iostream>
using namespace std;

int f[1000010] = {1, 1}, a[1000010] = {0, 1};
int n;

int main() {
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    f[i] = (f[i - 1] + f[i - 2] + a[i - 2] * 2) % 10000;
    a[i] = (f[i - 1] + a[i - 1]) % 10000;
  }
  cout << f[n];
  return 0;
}