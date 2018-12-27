/*
#include <iostream>
using namespace std;
int stick(int N,int cnt,int a);
int main()
{
	int X,count=1,res;
	cin>>X;
	res = stick(X,count,64);
	cout<<res;
}

int stick(int N,int cnt,int a)
{
	if(N==a) return cnt;
	else if(N>a){
		N-=a;
		a/=2;
		stick(N,++cnt,a);
	}
	else{
		a/=2;
		stick(N,cnt,a);
	}
}
*/
