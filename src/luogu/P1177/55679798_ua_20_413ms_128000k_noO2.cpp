#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

void qsort(int l, int r) {
  int mid = a[(l + r) >> 1];
  int i = l, j = r;
  do {
    while (a[i] < mid) {
      ++i;
    }
    while (a[j] > mid) {
      --j;
    }
    if (i < j) {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
      ++i;
      --j;
    }
  } while (i < j);
  if (l < j) {
    qsort(l, j);
  }
  if (i < r) {
    qsort(i, r);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.emplace_back(x);
  }
  qsort(0, n - 1);
  for (auto i : a) {
    cout << i << ' ';
  }
  return 0;
}