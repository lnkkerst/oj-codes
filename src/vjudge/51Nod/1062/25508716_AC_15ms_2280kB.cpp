//
// Created by lnkkerst on 2020/4/27/027.
//

#include <algorithm>
#include <iostream>
using namespace std;

int a[100010] = {0, 1};

int main() {
  for (int i = 1; i <= 50000; ++i) {
    a[i * 2] = a[i];
    a[i * 2 + 1] = a[i] + a[i + 1];
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << *max_element(a, a + n + 1) << endl;
  }
  return 0;
}
