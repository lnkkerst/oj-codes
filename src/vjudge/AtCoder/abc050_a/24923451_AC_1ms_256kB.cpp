#include <iostream>
using namespace std;

int a, b;
char op;

int main() {
  cin >> a >> op >> b;
  if (op == '+')
    cout << a + b;
  else
    cout << a - b;
  return 0;
}