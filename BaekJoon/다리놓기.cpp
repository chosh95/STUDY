#include <iostream>
using namespace std;
long long p[31][31];
int main()
{
	int a,b,T;
	cin>>T;
	for(int i=1;i<=30;i++){
		p[i][1] = i;
		p[i][i] = 1;
	}
	
	for(int i=2;i<=30;i++){
		for(int j=2;j<=i;j++){
			p[i][j] = (p[i][j-1] *(i-j+1))/j;   
		}
	}
	for(int i=1;i<=T;i++){
		cin>>a>>b;
		cout<<p[b][a]<<endl;
	}
}
