#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  auto c = a;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  c[0] = 1;
  for(int i = 1; i <= n; ++i) {
    c[i] = c[i - 1] * a[i];
  }
  vector<int> ans;

}
