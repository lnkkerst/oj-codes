#include <iomanip>
#include <iostream>
using namespace std;

double n, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  cout << fixed << setprecision(10)
       << (6 * n * k - 6 * k * k + 6 * k - 3 * n - 2) / (n * n * n);
  return 0;
}