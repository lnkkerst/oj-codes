#include <iostream>
#include <vector>
using namespace std;

int a[66], b[66];
char ch;
int n;

bool pd(vector<int> &x, vector<int> &y) {
  if (x.size() != y.size()) {
    return 0;
  }
  bool ret = 1;
  for (int i = 1; i <= n; ++i) {
    int pos = i;
    for (int j = 1; j <= n; ++j) {
      if (x[j] != y[pos]) {
        break;
      }
      if (pos == n) {
        pos = 1;
      } else {
        ++pos;
      }
    }
    if (pos == i && x[n] == y[pos]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  while (cin >> ch) {
    a[++n] = ch - '0';
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      b[i] = a[i] * k;
    }
    for (int i = n; i >= 1; --i) {
      b[i - 1] += b[i] / 10, b[i] %= 10;
    }
    vector<int> x, y;
    int pos = 1;
    x.push_back(0);
    y.push_back(0);
    while (!a[pos]) {
      ++pos;
    }
    for (int i = pos; i <= n; ++i) {
      x.push_back(a[i]);
    }
    pos = 1;
    while (!b[pos]) {
      ++pos;
    }
    for (int i = pos; i <= n; ++i) {
      y.push_back(b[i]);
    }
    if (!pd(x, y)) {
      return cout << 0, 0;
    }
  }
  return cout << 1, 0;
}
