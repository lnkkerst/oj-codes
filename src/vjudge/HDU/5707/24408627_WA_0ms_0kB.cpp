#include <iostream>
using namespace std;

string a, b, c;
int cnta[233], cntb[233], cntc[233];

int main() {
    while(cin >> a >> b >> c) {
        bool fl = 1;
        for(auto i : a) ++cnta[i];
        for(auto i : b) ++cntb[i];
        for(auto i : c) ++cntc[i];
        for(int i = 0; i < 233; ++i)
            if(cntc[i] != cnta[i] + cntb[i]) {
                puts("No");
                fl = 0;
                break;
            }
        if(!fl) continue;
        int posa = 0, posb = 0;
        for(auto i : c) {
            if(i == a[posa] && posa < (int)a.length()) ++posa;
            if(i == b[posb] && posb < (int)b.length()) ++posb;
        }
        if(posa == (int)a.length() && posb == (int)b.length()) puts("Yes");
        else puts("No");
    }
    return 0;
}