#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double ml;
  int n;
  cin >> ml >> n;
  cout << fixed << setprecision(2) << ml / n << endl << n * 2;
  return 0;
}