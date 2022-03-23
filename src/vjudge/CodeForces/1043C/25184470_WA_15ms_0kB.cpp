#include <iostream>
using namespace std;

int main() {
    char ch = getchar(), last = ch;
    while((ch = getchar()) != EOF) {
        if(ch != last) putchar('1');
        else putchar('0');
        putchar(' ');
        last = ch;
    }
    putchar((ch == 'a') + '0');
    return 0;
}