class Solution {
public:
  int reversePairs(vector<int> &nums) {
    int ret = 0, len = nums.size();
    for (int i = 0; i < len; ++i)
      for (int j = i + 1; j < len; ++j)
        ret += nums[i] > nums[j] * 2ll;
    return ret;
  }
};