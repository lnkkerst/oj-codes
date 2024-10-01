#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  puts((a + b + c) & 1 ? "win" : "lose");
  return 0;
}
