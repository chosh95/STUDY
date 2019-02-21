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
	char *p = new char[N+1];
	scanf("%s",p);
	int res=0;
	for(int i=0;i<=N;i++){
		res += p[i];
	}
	res	-= 48*N;
	cout<<res;
} 
<<<<<<< HEAD
=======
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
