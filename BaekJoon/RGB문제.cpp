#include <iostream> 
using namespace std;
int dp[1001][4]; // 
int p[1001][4]; //p[i][1,2,3] : i¹øÂ° ÁýÀÇ »¡°­,ÃÊ·Ï,ÆÄ¶ûÀÇ È®·ü 
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb

int main()
{
	int N;
	cin>>N;	
	for(int i=1;i<N+1;i++){
		for(int j=0;j<3;j++){
			cin>>p[i][j+1]; 
		}
	}
	dp[1][1] = p[1][1];
	dp[1][2] = p[1][2];
	dp[1][3] = p[1][3];
	for(int i=2;i<N+1;i++){
		dp[i][1] = min(dp[i-1][2],dp[i-1][3]) + p[i][1];
		dp[i][2] = min(dp[i-1][1],dp[i-1][3]) + p[i][2];
		dp[i][3] = min(dp[i-1][1],dp[i-1][2]) + p[i][3];
	}
	int res;
	res = min(dp[N][1],dp[N][2]);
	res = min(res,dp[N][3]);
	cout<<res;
}
