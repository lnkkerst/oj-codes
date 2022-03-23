#include<stdio.h>
int main(){
    int a[2001]={6},ans=0,n,b[10]={6,2,5,5,4,5,6,3,7,6};
    scanf("%d",&n);
    n=n-4;
    for(int i=1,j;i<=2000;i++){
        j=i;
        while(j>=1){
            a[i]=a[i]+b[j%10];
            j=j/10;
        }
    }
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
        	if(a[i]+a[j]+a[i+j]==n) ans++;
    printf("%d",ans);
    return 0;
}