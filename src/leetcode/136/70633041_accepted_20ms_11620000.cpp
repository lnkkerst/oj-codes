class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ret = 0;
    for (const auto &i : nums) {
      ret ^= i;
    }
    return ret;
  }
};
