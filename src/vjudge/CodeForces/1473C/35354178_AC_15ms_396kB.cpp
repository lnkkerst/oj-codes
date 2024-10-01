#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int i = 0; i < p.size(); ++i) {
      p[i] = i + 1;
    }
    reverse(p.begin() + (k * 2 - n) - 1, p.end());
    for (auto i : p) {
      cout << i << ' ';
    }
    cout << endl;
  }
}
