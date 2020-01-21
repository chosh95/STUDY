#include <iostream>
using namespace std;
int fes1(int a);
int fes2(int b);

int main()
{
	int a,b,T = 0,res=0;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>a>>b;
		res = fes1(a);
		res += fes2(b);
		cout<<res<<"\n";
	}
	return 0;
}

int fes1(int a){
	if(a==1) return 5000000;
	else if(a==2 || a==3) return 3000000;
	else if(a>=4 && a<=6) return 2000000;
	else if(a>=7 && a<=10) return 500000;
	else if(a>=11 && a<=15) return 300000;
	else if(a>=16 && a<=21) return 100000;
	else return 0;
}
int fes2(int b){
	if(b==1) return 5120000;
	else if(b==2 || b==3) return 2560000;
	else if(b>=4 && b<=7) return 1280000;
	else if(b>=8 && b<=15) return 640000;
	else if(b>=16 && b<=31) return 320000;
	else return 0;
}
