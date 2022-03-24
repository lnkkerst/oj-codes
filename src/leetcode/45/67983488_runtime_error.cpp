class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0, ret = 0;
        while(pos < (int)nums.size() - 1) {
            int nex = -1, ma = -1;
            for(int i = pos + 1; i <= pos + nums[pos] && i < (int)nums.size(); ++i) {
                if(nums[i] + i > ma) {
                    nums[i] + i;
                    ma = i;
                }
            }
            pos = ma;
            ++ret;
            if(pos + nums[pos] >= nums.size() - 1) break;
        }
        return ret;
    }
};