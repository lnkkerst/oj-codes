int maxProduct(int* a, int n){
    int ans = -1e9;
    for(int i = 0; i < n; ++i) {
        int tmp = 1;
        for(int j = i; j < n; ++j) {
            tmp *= a[j];
            ans = ans > tmp ? ans : tmp;
        }
    }
    return ans;
}