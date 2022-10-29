#include <iostream>
using namespace std;
int main() {
  long long s, e, sum = 0;
  cin >> s >> e;
  for (int i = s; i <= e; i++)
    if (i % 2 != 0 || i % 4 == 0)
      sum++;
  cout << sum;
  return 0;
}