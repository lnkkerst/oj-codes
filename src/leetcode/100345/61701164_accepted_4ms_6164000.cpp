class Solution {
public:
    int ans = 0;
    int dfs(int x) {
        ans += x;
        (x == 1) || (dfs(x - 1));
        return ans;
    }
    int sumNums(int n) {
        return dfs(n);
    }
};