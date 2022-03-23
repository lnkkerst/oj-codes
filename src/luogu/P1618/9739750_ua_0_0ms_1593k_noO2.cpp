#include<cstdio>
using namespace std;
bool pd(int x,int y){
	int a[3]={x%10,x/10%10,x/100},b[3]={y%10,y/10%10,y/100};
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if (a[i]==b[j]) return 0;
		}
	}
	return 1;
}
bool pd2(int x){
	int a=x%10,b=x/10%10,c=x/100;
	if (a!=b&&a!=c&&b!=c&&a!=0&&b!=0&&c!=0) return 1;
	return 0;
}
int main(){
	int a,b,c,x,y,z;
	scanf("%ld%ld%ld",&a,&b,&c);
	for (int i=100;i<=999/c*a;i++){
		x=i;y=i/a*b;z=i/a*c;
		if (pd(x,y)==1&&pd(x,z)==1&&pd(y,z)==1&&pd2(x)==1&&pd2(y)==1&&pd2(z)==1) printf("%ld %ld %ld\n",x,y,z);
	}
	return 0;
}