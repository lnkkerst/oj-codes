#include <iostream>
using namespace std;

int a[3] = {1};

int main() {
    char ch;
    while(cin >> ch) {
        char tmp;
        cin >> tmp;
        cin >> tmp;
        swap(a[ch - 'A'], a[tmp - 'A']);
    }
    for(int i = 0; i < 3; ++i)
        if(a[i]) {
            cout << (char)(i + 'A') << endl;
            return 0;
        }
    return 0;
}