#include<cstdio>
using namespace std;
int main(){
    char x[200],y[200],z[200];
    int n;
    scanf("%ld%s%s",&n,x,y);
    for (int i=0;i<n;i++){
        if (y[i]>x[i]){
            printf("-1");
            return 0;
        }
        else if (y[i]<x[i]){
            z[i]=y[i];
        }
        else if (y[i]=x[i]){
            z[i]=x[i]+1;
        }
    }
    printf("%s",z);
    return 0;
}