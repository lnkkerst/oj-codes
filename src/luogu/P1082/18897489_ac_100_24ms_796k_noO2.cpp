#include <cstdio>
#include <cctype>
#define int long long

using namespace std;

int x, y, a, b;

int read() {
    int res;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(res = ch - '0'; isdigit(ch = getchar()); res *= 10, res += ch -'0');
    (flag == 1) && (res *= -1);
    return res;
}

void print(int x) {
    if(x < 0) {
        putchar('-');
        x *= -1;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

#undef int 
int main() {
    #define int long long
    a = read();
    b = read();
    exgcd(a, b, x, y);
    x = (x % b + b) % b;
    print(x);
    return 0;
}