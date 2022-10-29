#include <iostream>
using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  if (m % n)
    cout << m % n;
  else
    cout << m / n;
  return 0;
}