#include <bits/stdc++.h>
using namespace std;

void work(int n) {
  int i = 0, cnt = 0, h[50];
  while (n) {
    if (n & 1) {
      h[++cnt] = i;
    }
    n >>= 1, ++i;
  }
  while (cnt) {
    if (h[cnt] < 3) {
      if (h[cnt] == 1 && cnt != 1) {
        cout << "2+";
      } else if (h[cnt] == 1) {
        cout << "2";
      }
      if ((!h[cnt] || h[cnt] == 2) && cnt != 1) {
        cout << "2(" << h[cnt] << ")+";
      } else if (!h[cnt] || h[cnt] == 2) {
        cout << "2(" << h[cnt] << ")";
      }
      --cnt;
    } else {
      cout << "2(";
      work(h[cnt--]);
      if (cnt) {
        cout << ")+";
      } else {
        cout << ")";
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  work(n);
  return 0;
}
