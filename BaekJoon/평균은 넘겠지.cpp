#include <iostream>
using namespace std;

int main()
{
	int C,N,res=0,sum=0;
	double avg=0.0;
	cin>>C;
	for(int i=1;i<=C;i++){
		sum=res=avg=0;
		cin>>N;
		int *p = new int[N+2];
		for(int j=1;j<=N;j++){
			cin>>p[j];
			sum+=p[j];
		}
		avg = (double)sum/(double)N;
		for(int j=1;j<=N;j++){
			if(p[j]>avg) res++;
		}
		avg = (double)res/(double)N;
		avg*=100;
		printf("%.3lf\%\n",avg);
	}
}
