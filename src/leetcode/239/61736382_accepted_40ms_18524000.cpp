class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ret;
		int a[100001][15] = {0};
		for(int i = 1; i <= (int)nums.size(); ++i)
			a[i][0] = nums[i - 1];
		for(int j = 1; j <= 14; ++j)
			for(int i = 1; i + (1 << j) - 1 <= nums.size(); ++i)
				a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
		int t = log2(k);
		for(int i = 1; i + k - 1 <= nums.size(); ++i)
			ret.push_back(max(a[i][t], a[i + k - 1 - (1 << t) + 1][t]));
		return ret;
    }
};