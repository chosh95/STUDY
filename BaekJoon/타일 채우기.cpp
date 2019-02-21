<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int dp[41] = {1,0,3};
	for(int i=4;i<=N;i+=2){
		dp[i] = dp[i-2] * 3;
		for(int j=4;j<=i;j+=2){
			dp[i]+=2*dp[i-j];
		}
	}	
	cout<<dp[N];
	return 0;
}
<<<<<<< HEAD

=======
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
