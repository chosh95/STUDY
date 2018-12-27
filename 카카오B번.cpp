/*
#include <iostream>
#include <math.h>
using namespace std;
int a[501];
double m[501];
double v[501];
double d[501];
double res[501]; 
void getvariance(int N,int K);
void getaverage(int N,int K);
double getdeviation(int N,int K);

int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N;i++)	cin>>a[i]; 
	double min;
	for(int i=K;i<=N;i++){
		getaverage(N,i);
		getvariance(N,i);
		res[i] = getdeviation(N,i);
		if(i==K) min = res[i];
		else if(res[i]<min) min = res[i];
	}
	
	
	cout<<fixed;
	cout.precision(11);
	cout<<min;
}

void getaverage(int N,int K)
{
	for(int i=0;i<N-K+1;i++)
	{
		for(int j=i;j<i+K;j++)
		{
			m[i] += a[j];
		}
		m[i] /= K;
	}
}

void getvariance(int N,int K)
{
	for(int i=0;i<N-K+1;i++)
	{
		for(int j=i;j<i+K;j++)
		{
			v[i] += (a[j]-m[i])*(a[j]-m[i]);
		}
		v[i] /= K;
	}
}

double getdeviation(int N,int K)
{
	double min = 0;
	for(int i=0;i<N-K+1;i++)
	{
		d[i] = sqrt(v[i]);
		if(i==0) min = d[0];
		else if(d[i]<=min) min = d[i];
	}
	return min;
}
*/
