#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  vector<int> a(n + 1, -1);
  for (auto &i : b) {
    cin >> i;
  }
  b.emplace_back(b.back());
  for (int k = 1; k <= 10; ++k) {
    for (int i = 0; i < n - 1; ++i) {
      if (b[i] == 0) {
        a[i] = a[i + 1] = 0;
        continue;
      } else if (b[i + 1] > b[i]) {
        a[i + 2] = b[i + 1];
        if (a[i] != b[i]) {
          if (a[i] == -1) {
            a[i] = b[i];
            a[i + 1] = 0;
          } else {
            a[i + 1] = b[i];
          }
        } else {
          a[i + 1] = 0;
        }
      } else if (b[i + 1] < b[i]) {
        a[i] = b[i];
      }
      // else if (b[i + 1] == b[i]) {
      //   if (a[i + 1] == b[i]) {
      //     if (a[i - 1] == -1) {
      //       a[i - 1] = 0;
      //     }
      //     a[i + 2] = 0;
      //   } else if (a[i] == b[i]) {
      //     if (a[i + 1] != b[i]) {
      //       a[i + 2] = a[i];
      //     } else {
      //     }
      //   }
      // }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      a[i] = b[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
