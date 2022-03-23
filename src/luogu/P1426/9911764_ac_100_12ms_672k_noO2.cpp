#include<cstdio>
using namespace std;
int main(){
    double s,x,v=7,st=0;
    scanf("%lf%lf",&s,&x);
    while (st<s-x){
        st=st+v;
        v=v*0.98;
    }
    if (st+v>s+x) printf("n");
    else printf("y");
    return 0;
}