#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    int ans = 0;
    priority_queue<int> q;
    for (auto i : piles) {
      ans += i;
      q.push(i);
    }
    for (int i = 1; i <= k; ++i) {
      int u = q.top();
      q.pop();
      int diff = u / 2;
      u -= diff;
      ans -= diff;
      q.push(u);
    }
    return ans;
  }
};
