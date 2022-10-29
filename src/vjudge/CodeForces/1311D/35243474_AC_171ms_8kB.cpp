#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool isPrime(int x) {
  if (x == 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 999999999;
    int ansa, ansb, ansc;
    for (int i = 1; i <= 20000; ++i) {
      for (int j = 1; i * j <= 20000; ++j) {
        for (int k = 1; i * j * k <= 20000; ++k) {
          int tot = abs(a - i) + abs(b - i * j) + abs(c - i * j * k);
          if (tot < ans) {
            ans = tot;
            ansa = i;
            ansb = i * j;
            ansc = i * j * k;
          }
        }
      }
    }
    cout << ans << endl << ansa << ' ' << ansb << ' ' << ansc << endl;
  }
}