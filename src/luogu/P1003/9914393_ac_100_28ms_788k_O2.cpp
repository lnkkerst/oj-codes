// luogu-judger-enable-o2
#include<cstdio>
using namespace std;
int main(){
    int n,x,y;
    bool flag=0;
    scanf("%ld",&n);
    const int N=n;
    int a[N][4];
    for (int i=0;i<n;i++) scanf("%ld%ld%ld%ld",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    scanf("%ld%ld",&x,&y);
    for (int i=n-1;i>=0;i--)
        if (a[i][0]<=x&&a[i][2]+a[i][0]>=x&&a[i][1]<=y&&a[i][3]+a[i][1]>=y){
            printf("%ld",i+1);
            flag=1;
            break;
        }
    if (flag==0) printf("-1");
    return 0;
}