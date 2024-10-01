#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

int main() {
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  cout << *min_element(a.begin(), a.end());
  return 0;
}
