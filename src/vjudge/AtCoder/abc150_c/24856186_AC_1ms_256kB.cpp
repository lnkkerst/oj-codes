#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a, b;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  bool fl = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] > b[i]) {
      fl = 1;
      break;
    } else if (a[i] < b[i])
      break;
  }
  if (fl)
    swap(a, b);
  int ans = 0;
  do {
    fl = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
      if (a[i] != b[i]) {
        fl = 1;
        break;
      }
    }
    if (!fl)
      break;
    ++ans;
  } while (next_permutation(a.begin(), a.end()));
  cout << ans;
  return 0;
}