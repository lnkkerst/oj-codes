#include <iostream>
#include <queue>
using namespace std;

int x;
queue<int> a;

int main() {
  cin >> x;
  queue<int> t;
  while (x) {
    t.push(x % 2);
    x >>= 1;
  }
  while (!t.empty()) {
    a.push(t.front());
    t.pop();
  }
  int ans = -1;
  for (int i = 1; i <= (int)a.size(); ++i) {
    t = a;
    int cnt = 0, tmp = 0;
    while (!t.empty()) {
      tmp += t.front() << cnt++;
      t.pop();
    }
    ans = max(ans, tmp);
    int tmpp = a.front();
    a.pop();
    a.push(tmpp);
  }
  cout << ans;
  return 0;
}