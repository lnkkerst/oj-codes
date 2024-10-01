#include <bits/stdc++.h>
using namespace std;

int n, ans;
deque<int> a;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  string ans;
  int now = 0;
  while (!a.empty() && (a.front() >= now || a.back() >= now)
         && (int)ans.size() != n) {
    if (a.front() > a.back()) {
      if (a.back() > now) {
        now = a.back();
        a.pop_back();
        ans.push_back('R');
      } else if (a.front() > now) {
        now = a.front();
        a.pop_front();
        ans.push_back('L');
      } else {
        break;
      }
    } else if (a.front() < a.back()) {
      if (a.front() > now) {
        now = a.front();
        a.pop_front();
        ans.push_back('L');
      } else if (a.back() > now) {
        now = a.back();
        a.pop_back();
        ans.push_back('R');
      } else {
        break;
      }
    } else {
      int lans = 0, rans = 0, lnow = now, rnow = now;
      deque<int> q = a;
      while (!q.empty()) {
        if (q.front() > lnow) {
          ++lans, lnow = q.front(), q.pop_front();
        } else {
          break;
        }
      }
      q = a;
      while (!q.empty()) {
        if (q.back() > rnow) {
          ++rans, rnow = q.back(), q.pop_back();
        } else {
          break;
        }
      }
      if (lans > rans) {
        now = a.front();
        a.pop_front();
        ans.push_back('L');
      } else {
        now = a.back();
        a.pop_back();
        ans.push_back('R');
      }
    }
  }
  cout << (int)ans.size() << endl << ans;
}
