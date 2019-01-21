#include <iostream> 
using namespace std;
int cycle(int initn,int n,int cnt);

int main()
{
	int N,count=0,res;
	cin>>N;
	res = cycle(N,N,count);
	cout<<res<<" ";
}

int cycle(int initn,int n,int cnt)
{
	if(initn==n && cnt!=0) return cnt; 
	else if(n<10){
		n*=11;
		cycle(initn,n,++cnt);
	}
	else{
		int tmp1 = n%10;
		int tmp2 = n/10+n%10;
		n = tmp1*10 + tmp2%10;
		cycle(initn,n,++cnt);
	}
}
