#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);
    const int N=n;
    int a[N];
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    for (i=N-1;i>0;i--)
        if (a[i]==a[i-1]) a[i]=0;
    for (i=0;i<n;i++)
        if (a[i]!=0) printf("%d ",a[i]);
    return 0;
}