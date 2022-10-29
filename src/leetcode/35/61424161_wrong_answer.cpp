class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    auto num = lower_bound(nums.begin(), nums.end(), target);
    if (*num == target)
      return num - nums.begin();
    nums.insert(--num, target);
    return 0;
  }
};