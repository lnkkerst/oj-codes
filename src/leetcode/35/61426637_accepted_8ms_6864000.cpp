class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    auto num = lower_bound(nums.begin(), nums.end(), target);
    if (num == nums.end()) {
      nums.push_back(target);
      return nums.size() - 1;
    }
    if (*num == target) {
      return num - nums.begin();
    }
    int ret = num - nums.begin();
    nums.insert(num, target);
    return ret;
  }
};
