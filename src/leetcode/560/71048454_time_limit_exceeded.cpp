class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int ret = nums.size() && nums[0] == k;
    for (int i = 1; i < (int)nums.size(); ++i)
      nums[i] += nums[i - 1];
    for (int i = 1; i < (int)nums.size(); ++i) {
      ret += nums[i] == k;
      for (int j = i; j < (int)nums.size(); ++j)
        if (nums[j] - nums[i - 1] == k)
          ++ret;
    }
    return ret;
  }
};