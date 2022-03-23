#include <iostream>
#include <map>
#include <set>
using namespace std;

int n, t, q;
set<string> word;
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
            word.insert(str);
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
                cout << (word.find(str.substr(l, r - l + 1)) != word.end() ? "Yes\n" : "No\n");
            }
        }
    }
    return 0;
}