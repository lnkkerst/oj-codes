class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() <= 1)
      return 0;
    int ret = 0;
    vector<int> lm, rm;
    lm.reserve(height.size() + 1);
    rm.reserve(height.size() + 1);
    lm[0] = height[0], rm[height.size() - 1] = height.back();
    for (int i = 1; i < (int)height.size(); ++i)
      lm[i] = max(lm[i - 1], height[i]);
    for (int i = (int)height.size() - 2; i >= 0; --i)
      rm[i] = max(rm[i + 1], height[i]);
    for (int i = 0; i < (int)height.size(); ++i)
      ret += min(lm[i], rm[i]) - height[i];
    return ret;
  }
};