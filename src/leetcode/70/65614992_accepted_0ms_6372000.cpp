class Solution {
public:
    int climbStairs(int n) {
        vector<long long> f(n + 2);
        f[0] = 0, f[1] = 1;
        for(int i = 2; i <= n + 1; ++i)
            f[i] = f[i - 1] + f[i - 2];
        return f[n + 1];
    }
};