class Solution {
public:
	int cnt;
	Solution() : cnt(0) {}
	void msort(int l, int r, vector<int> &a, vector<int> &b) {
		if(l == r) return ;
		int mid = (l + r) >> 1;
		msort(l, mid, a, b);
		msort(mid + 1, r, a, b);
		int i = l, j = mid + 1, t = l;
		while(i <= mid && j <= r)
			if(a[i] <= a[j]) b[t++] = a[i++];
			else b[t++] = a[j++], cnt += mid - i + 1;
		while(i <= mid) b[t++] = a[i++];
		while(j <= r) b[t++] = a[j++];
		for(int i = l; i <= r; ++i) a[i] = b[i];
	}
    int reversePairs(vector<int>& nums) {
        vector<int> b(nums.size());
		msort(0, nums.size() - 1, nums, b);
		return cnt;
    }
};