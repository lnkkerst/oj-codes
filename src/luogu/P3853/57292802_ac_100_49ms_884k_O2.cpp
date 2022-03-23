#include <iostream>
#include <vector>
using namespace std;

int main() {
    int len, n, k;
    cin >> len >> n >> k;
    vector<int> a;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.emplace_back(x);
    }

    int l = 0, r = len;
    while(l < r) {
        int mid = (l + r) >> 1;
        int tmp = 0;
        for(int i = 1; i < n; ++i) {
            tmp += (a[i] - a[i - 1] - 1) / mid;
        }
        if(tmp > k) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << l;
    return 0;
}