#pragma GCC optimize(3)
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums;
  }
};
