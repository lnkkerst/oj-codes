#include <iostream>
#include <map>
using namespace std;

int n, t, q;
map<string , bool > word;
string str;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);
    cin >> t;
    for(int k = 1; k <= t; ++k) {
        printf("Case #%d:\n", k);
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> str;
            word[str] = 1;
        }
        cin >> str >> q;
        for(int i = 1; i <= q; ++i) {
            char opt;
            cin >> opt;
            if(opt == 'C') {
                int pos;
                char ch;
                cin >> pos >> ch;
                str[pos] = ch;
            }
            else {
                int l, r;
                cin >> l >> r;
                cout << (word[str.substr(l, r - l + 1)] ? "Yes\n" : "No\n");
            }
        }
    }
    return 0;
}