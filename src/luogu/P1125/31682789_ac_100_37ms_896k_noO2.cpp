#include <iostream>
#include <algorithm>
using namespace std;

char ch;
int cnt[26];

bool pd(int x) {
    if(x == 1) return 0;
    if(x == 2 || x == 3) return 1;
    if(x % 6 != 1 && x % 6 != 5) return 0;
    for(int i= 5; i * i <= x; i += 6)
        if(x % i == 0 || x % (i + 2) == 0)
            return 0;
    return 1;
}

int main() {
    while(cin >> ch) ++cnt[ch - 'a'];
    int maxn = -1, minn = (int)1e9;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] > maxn) maxn = cnt[i];
        if(cnt[i] && cnt[i] < minn) minn = cnt[i];
    }
    if(pd(maxn - minn)) cout << "Lucky Word\n" << maxn - minn << endl;
    else cout << "No Answer\n0";
    return 0;
}