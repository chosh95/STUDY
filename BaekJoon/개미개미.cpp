<<<<<<< HEAD
=======
/*
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	long long p[3];
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%lld%lld%lld",&p[0],&p[1],&p[2]);
		sort(p,p+3); 
		printf("%lld\n",p[2]*p[2]+(p[0]+p[1])*(p[0]+p[1]));
	}	
}
<<<<<<< HEAD
=======
*/
>>>>>>> 9fe011e74c4cca81972d57c2f802553362fea3eb
