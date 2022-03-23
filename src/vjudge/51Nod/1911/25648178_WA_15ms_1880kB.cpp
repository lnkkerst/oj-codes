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
    for(int i = (n >> 1) + 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt2 += x;
    }
    puts(cnt1 == cnt2 ? "Yes" : "No");
    return 0;
}