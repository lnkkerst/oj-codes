#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(x) a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
    }
    int ans = -1;
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[j] - a[i - 1] == 0)
                ans = max(ans, j - i + 1);
    cout << ans;
    return 0;
}