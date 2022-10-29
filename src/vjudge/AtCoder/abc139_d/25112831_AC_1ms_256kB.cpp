#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (((long long)n * n - n) >> 1);
  return 0;
}