#include <iostream> 
using namespace std;
int dp[1001][1001];
int p[1001];

int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>p[i];
	
	for(int i=0;i<=N;i++) dp[1][i] = p[1]*i;
	for(int i=1;i<=N;i++) dp[i][0] = 0;	

	for(int i=2;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(j>=i) dp[i][j] = max(dp[i-1][j],p[i]+dp[i][j-i]);
			else if(j<i) dp[i][j] = dp[i-1][j];
		}
	}
	
	
	cout<<dp[N][N];
}
