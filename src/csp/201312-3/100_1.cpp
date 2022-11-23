#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    int mi = a[i];
    for (int j = i; j < a.size(); ++j) {
      mi = min(mi, a[j]);
      ans = max(ans, mi * (j - i + 1));
    }
  }
  cout << ans << endl;
  return 0;
}
