#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    set<int> b;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.emplace_back(x);
    }
    int ans = a[0];
    b.insert(a[0]);
    for(int i = 1; i < n; ++i) {
        auto it = b.lower_bound(a[i]);
        if(it == b.end()) {
            ans += a[i] - *b.rbegin();
        }
        else if(*it ==  a[i]) {

        }
        else if(*it > a[i]) {
            int t = abs(*it - a[i]);
            if(it != b.begin()) {
                --it;
                if (t > abs(a[i] - *it)) {
                    t = abs(a[i] - *it);
                }
            }
            ans += t;
        }
        b.insert(a[i]);
//        cout << ans << endl;
    }
    cout << ans;
    return 0;
}