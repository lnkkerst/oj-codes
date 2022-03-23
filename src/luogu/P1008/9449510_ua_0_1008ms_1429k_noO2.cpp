#include<cstdio>
using namespace std;
int main(){
	int x,y,z,t;
	for (int a=1;a<=9;a++)
		for (int b=1;b<=9;b++)
			for (int c=1;c<=9;c++)
				for (int d=1;d<=9;d++)
					for (int e=1;e<=9;e++)
						for (int f=1;f<=9;f++)
							for (int g=1;g<=9;g++)
								for (int h=1;h<=9;h++)
									for (int i=1;i<=9;i++){
										if ((a*100+b*10+c)*6==(d*100+e*10+f)*3&&(a*100+b*10+c)*6==(g*100+h*10+i)*2&&a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&a!=g&&a!=h&&a!=i&&b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&b!=h&&b!=i&&c!=d&&c!=e&&c!=f&&c!=g&&c!=h&&c!=i&&d!=e&&d!=f&&d!=g&&d!=h&&d!=i&&e!=f&&e!=g&&e!=h&&e!=i&&f!=g&&f!=h&&f!=i&&g!=h&&g!=i&&h!=i){
											x=(a*100+b*10+c);y=(d*100+e*10+f);z=(g*100+h*10+i);
											if (x>y){
												t=x;
												x=y;
												y=t;
											}
											if (y>z){
												t=y;
												y=z;
												z=t;
											}
											if (x>y){
												t=x;
												x=y;
												y=t;
											}
											printf("%d %d %d\n",x,y,z);
										}
									}
	return 0;
}