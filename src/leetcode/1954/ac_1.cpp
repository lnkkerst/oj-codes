#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minimumPerimeter(long long neededApples) {
    long long cur = 1;
    long long cnt = 12;
    while (cnt < neededApples) {
      ++cur;
      cnt = cur * 2 * (cur + 1) * (cur * 2 + 1);
    }
    return cur * 8;
  }
};
