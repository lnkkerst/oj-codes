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
    int mu = 1, cnt = 0;
    for (auto i : nums) {
      (i) && (mu *= i), cnt += !i;
    }
    vector<int> ret;
    if (cnt) {
      if (cnt == 1) {
        for (auto i : nums) {
          if (i) {
            ret.push_back(0);
          } else {
            ret.push_back(mu);
          }
        }
      } else {
        ret.resize(nums.size());
      }
      return ret;
    }
    for (auto i : nums) {
      ret.push_back(div(mu, i));
    }
    return ret;
  }
};
