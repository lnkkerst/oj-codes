#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= (n >> 1); ++i) {
        int x;
        cin >> x;
        cnt1 += x;
    }
    int x = 0;
    if(n & 1) cin >> x;
    for(int i = 1; i <= (n >> 1); ++i) {
        int x;
        cin >> x;
        cnt2 += x;
    }
    if(cnt1 + x == cnt2 || cnt1 == cnt2 + x) puts("Yes");
    else puts("No");
    return 0;
}