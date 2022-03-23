#include <iostream>
#define int long long
using namespace std;

int n;
string str;

void print(int x) {
    if(!x) return ;
    print(x / 3);
    putchar(x % 3 + '0');
}

signed main() {
    cin >> n;
    while(n--) {
        cin >> str;
        int num = 0;
        for(int i = 0; i < (int)str.length(); ++i)
            num += (str[i] - '0') * (1 << ((int)str.length() - i - 1));
        print(num);
        cout << endl;
    }
    return 0;
}