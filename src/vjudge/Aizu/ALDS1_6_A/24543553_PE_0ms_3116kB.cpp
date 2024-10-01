#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  for (auto i : a) {
    cout << i << ' ';
  }
  return 0;
}
