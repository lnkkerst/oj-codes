#include <bits/stdc++.h>
using namespace std;

long long n, full;
long double ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    long long tmp;
    cin >> tmp;
    full += tmp;
  }
  cout << (long double)((long double)(full * full) / (long double)n) << endl;
  return 0;
}