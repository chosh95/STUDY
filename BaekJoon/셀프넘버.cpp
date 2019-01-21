#include <iostream>
using namespace std;
int p[10050];
void self(int n);
int main()
{
	for(int i=1;i<=10000;i++){
		self(i);
	}
	for(int i=1;i<=10000;i++){
		if(p[i]!=1) cout<<i<<"\n";
		else continue;
	}
}

void self(int n)
{
	if(n<10) p[n+n] = 1;
	else if(n<100) p[n+n/10+n%10] = 1;
	else if(n<1000){
		int tmp = n;
		tmp+=n/100;
		n%=100;
		tmp+=n/10;
		tmp+=n%10;
		p[tmp] = 1;	 
	}
	else if(n<10000){
		int tmp = n;
		tmp+=n/1000;
		n%=1000;
		tmp+=n/100;
		n%=100;
		tmp+=n/10;
		tmp+=n%10;
		p[tmp] = 1;
	}
	else if(n==10000) p[10001] = 1;
}
