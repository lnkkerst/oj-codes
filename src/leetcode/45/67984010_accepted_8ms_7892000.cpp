class Solution {
public:
    int jump(vector<int>& nums) {
        vector<bool> vis(nums.size());
        int pos = 0, ret = 0;
        while(1) {
            if(pos >= (int)nums.size() - 1)
                return ret;
            if(vis[pos]) return 0;
            vis[pos] = 1;
            int nex = 0, pt = pos;
            for(int i = 1; i <= nums[pos]; ++i) {
                if(i + pos >= (int)nums.size() - 1)
                    return ret + 1;
                if(nums[i + pos] + i >= nex) {
                    nex = nums[i + pos] + i;
                    pt = i + pos;
                }
            }
            pos = pt;
            ++ret;
        }
    }
};