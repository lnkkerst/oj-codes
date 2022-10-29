#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::cout << (n - 1 + k - 2) / (k - 1);
  return 0;
}