#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool isPrime(int x) {
  if (x == 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    string s;
    cin >> k >> s;
    vector<int> a;
    for (auto i : s) {
      a.emplace_back(i - '0');
    }
    bool fl = false;
    for (int i = 0; i < a.size(); ++i) {
      if (!isPrime(a[i])) {
        cout << 1 << endl << a[i] << endl;
        fl = true;
        break;
      }
    }
    if (fl)
      continue;
    for (int i = 0; i < a.size(); ++i) {
      bool fll = false;
      for (int j = i + 1; j < a.size(); ++j) {
        if (!isPrime(a[i] * 10 + a[j])) {
          fll = fl = true;
          cout << 2 << endl << a[i] * 10 + a[j] << endl;
          break;
        }
      }
      if (fll)
        break;
    }
  }
}