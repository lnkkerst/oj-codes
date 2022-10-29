#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    q.push(x);
  }
  int ans = 0;
  while (q.size() > 1) {
    int x = q.top();
    q.pop();
    int y = q.top();
    q.pop();
    ans += x + y;
    q.push(x + y);
  }
  cout << ans;
  return 0;
}