#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> a;
    for(int i = 1; i <= n; ++i) {
        int q, x;
        cin >> q >> x;
        if(q == 1) {
            int rk = 0;
            for(auto j : a) {
                if(j >= x) {
                    break;
                }
                ++rk;
            }
            cout << rk << endl;
        }
        if(q == 2) {
            auto ans = a.begin();
            for(int j = 1; j < x; ++j) {
                ++ans;
            }
            cout << *ans << endl;
        }
        if(q == 3) {
            int ans = -2147483647;
            for(auto j : a) {
                if(j < x) {
                    ans = j;
                }
            }
            cout << ans << endl;
        }
        if(q == 4) {
            int ans = 2147483647;
            for(auto j = a.rbegin(); j != a.rend(); ++j) {
                if(*j > x) {
                    ans = *j;
                }
            }
            cout << ans << endl;
        }
        if(q == 5) {
            a.insert(x);
        }
    }
    return 0;
}