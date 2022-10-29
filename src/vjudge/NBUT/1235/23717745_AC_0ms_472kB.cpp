#include <iostream>
using namespace std;

int a[] = {153, 370, 371, 407, 1634, 8208, 9474, 54748, 92727, 93084, 548834};

int main() {
  int l, r;
  while (cin >> l >> r)
    for (int i = 0; i <= 10; ++i)
      if (a[i] >= l && a[i] <= r)
        cout << a[i] << endl;
  return 0;
}