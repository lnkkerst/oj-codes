#include <algorithm>
#include <iostream>
using namespace std;

int a[10], n;

int main() {
  for (int i = 1; i <= 5; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + 6, greater<int>());
  for (int i = 1; i <= 4; ++i) {
    cout << a[i] << ' ';
  }
  cout << a[5] << endl;
  return 0;
}
