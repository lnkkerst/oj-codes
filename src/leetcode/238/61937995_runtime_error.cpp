class Solution {
public:
  int div(int x, int y) {
    int ret = 0, base = y, ab = 1;
    while (base * 10 <= x) {
      base *= 10, ab *= 10;
    }
    while (base) {
      while (x - base >= 0) {
        x -= base, ret += ab;
      }
      while (base > x) {
        base /= 10, ab /= 10;
      }
    }
    return ret;
  }
  vector<int> productExceptSelf(vector<int> &nums) {
    int mu = 1;
    for (auto i : nums) {
      mu *= i;
    }
    vector<int> ret;
    for (auto i : nums) {
      ret.push_back(div(mu, i));
    }
    return ret;
  }
};
