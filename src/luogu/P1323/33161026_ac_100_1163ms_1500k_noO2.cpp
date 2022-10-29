#include <iostream>
#include <queue>
#define int long long
using namespace std;

signed main() {
  int k, m;
  string s;
  priority_queue<int, vector<int>, greater<int>> q;
  cin >> k >> m;
  q.push(1);
  for (int i = 1; i <= k; ++i) {
    int t = q.top();
    s.append(to_string(t));
    q.pop();
    q.push(t * 2 + 1);
    q.push(t * 4 + 5);
  }
  cout << s << endl;
  int ans = 0;
  while (ans != m)
    for (int i = 0; ans != m && i < (int)s.length() - 1; ++i)
      if (s[i] < s[i + 1]) {
        ++ans;
        s.erase(i, 1);
        break;
      }
  cout << s;
  return 0;
}