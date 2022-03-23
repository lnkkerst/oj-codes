#include <iostream>
using namespace std;

int n;
int a[100001];
bool b[100001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(b[a[i]] || a[i] > n) a[i] = 0;
        if(a[i] <= n) b[a[i]] = true;
    }
    int pos = n;
    for(int i = 1; i <= n; ++i) {
        while(b[pos]) --pos;
        if(!a[i]) a[i] = pos, b[pos] = 1;
    }
    for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}