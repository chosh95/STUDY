#include <iostream>
using namespace std;
int main()
{
	int N,M;
	cin>>N>>M;
	int a,minnum;
	for(int i=1;i<=M;i++){
		if(i*i>=N){
			a = i;
			minnum = i*i;
			break;
		}
	}
	int res = 0;
	for(int i = a;i*i<=M;i++){
		res+=(i*i);
	}
	if(res==0) cout<<-1;
	else cout<<res<<endl<<minnum;
}
