#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  unordered_map<int, int> b;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++b[x];
  }
  int ans = b.begin()->first, ansCnt = b.begin()->second;
  for (auto i : b) {
    if (i.second > ansCnt) {
      ans = i.first;
      ansCnt = i.second;
    }
    if (i.second == ansCnt && i.first < ans) {
      ans = i.first;
    }
  }
  cout << ans << endl;
  return 0;
}
