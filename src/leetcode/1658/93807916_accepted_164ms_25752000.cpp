class Solution {
public:
    int cntC(vector<int>& a) {
        int ret = 0;
        for(auto i = a.rbegin(); i != a.rend(); ++i) {
            if(*i) return ret;
            ++ret;
        }
        return ret;
    }
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> a(grid.size());
        int n = grid.size(), ans = 0;
        for(int i = 0; i < n; ++i) a[i] = cntC(grid[i]);
        for(int i = 0; i < n - 1; ++i) {
            bool fl = 0;
            for(int j = i; j < n; ++j) {
                if(a[j] >= n - i - 1) {
                    fl = 1;
                    ans += j - i;
                    int tmp = a[j];
                    for(int k = j; k >= i + 1; --k) a[k] = a[k - 1];
                    a[i] = tmp;
                    break;
                }
            }
            if(!fl) return -1;
            // for(auto i : a) cout << i << endl;
        }
        return ans;
    }
};