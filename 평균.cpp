/*
#include <iostream>
using namespace std;

int main()
{
	int N;
	double max = 0,sum = 0;
	cin>>N;
	double *p = new double[N+1];
	for(int i=0;i<N;i++){
		cin>>p[i];
		if(max<p[i]) max = p[i];
	}
	for(int i=0;i<N;i++){
		p[i]/=max;
		p[i]*=100;
		sum+=p[i];
	}
	sum/=N;
	cout.precision(4);
	cout<<sum;
}
*/
