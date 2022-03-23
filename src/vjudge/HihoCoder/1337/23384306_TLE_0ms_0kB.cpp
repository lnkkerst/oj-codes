#include <iostream>
#include <set>
using namespace std;

set<int > a;
set<int >::iterator ans;
int n, x;
char opt;

int main() {
    cin >> n;
    while(n--) {
        cin >> opt >> x;
        if(opt == 'I') a.insert(x);
        else {
            ans = a.begin();
            for(int i = 1; i < x; ++i, ++ans);
            cout << *ans << endl;
        }
    }
    return 0;
}