class Solution {
public:
  int maxSubArray(vector<int> &a) {
    int ret = a[0], last = 0;
    for (auto &i : a)
      ret = max(ret, last = max(i, last + i));
    return ret;
  }
};