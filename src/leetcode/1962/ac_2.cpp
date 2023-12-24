#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    make_heap(piles.begin(), piles.end());
    for (int i = 1; i <= k; ++i) {
      pop_heap(piles.begin(), piles.end());
      piles.back() -= piles.back() / 2;
      push_heap(piles.begin(), piles.end());
    }
    return accumulate(piles.begin(), piles.end(), 0);
  }
};
