class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    do {
      ret.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ret;
  }
};
