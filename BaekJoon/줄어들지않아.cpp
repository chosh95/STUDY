#include <iostream>
using namespace std;
long long dp[65][65];
long long p[65];
int main()
{
	int T,N;
	cin>>T;
	
	p[1] = 10;
	p[2] = 55;
	for(int i=0;i<=9;i++) dp[2][i] = (10-i);
	for(int i=3;i<=64;i++){
		for(int j=0;j<=9;j++){
			if(j==0) dp[i][j] = p[i-1];
			else{
				dp[i][j] = dp[i][j-1]-dp[i-1][j-1];
			}
			p[i]+=dp[i][j];
		}
	}
		
	for(int i=1;i<=T;i++){
		cin>>N;
		cout<<p[N]<<endl;
	}
}
