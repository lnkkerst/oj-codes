class Solution {
public:
    int maxArea(vector<int>& a) {
        int l = 0, r = a.size() - 1;
		int ans = -1;
		while(l < r) {
			int t = min(a[l], a[r]) * (r - l);
			ans = max(ans, t);
			if(a[l] <= a[r]) ++l;
			else --r;
		}
		return ans;
    }
};