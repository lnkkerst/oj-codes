#include<cstdio>
using namespace std;
int main(){
	int p,a=0,m=0,c=0,n;
	for (int i=1;i<=12;i++){
		a+=300;
		scanf("%d",&p);
		if (a<p&&m==0){
			m=i;
		}
		else{
			n=(a-p)/100;
			a=a-p;
			if (n>0){c=c+n;a=a-n*100;}
		}
	}
	c=c*100;
	c=c+c*0.2;
	a=a+c;
	if (m!=0) printf("-%d",m);
	else printf("%d",a);
	return 0;
}