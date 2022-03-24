class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1e9;
        for(int i = 0; i < (int)nums.size(); ++i) {
            int tmp = 1;
            for(int j = i; j < (int)nums.size(); ++j) {
                tmp *= nums[j];
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};