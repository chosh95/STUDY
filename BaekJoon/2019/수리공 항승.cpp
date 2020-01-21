#include <iostream> 
#include <algorithm>
using namespace std;

int main()
{
	int N,L,count=1,i=1,j=1;
	cin>>N>>L;
	int *p = new int[N+2];
	int *q = new int[N*2+4];
	for(int i=1;i<=N;i++) cin>>p[i];
	sort(p+1,p+N+1);
	q[1] = p[1];
	q[2] = p[1]+L-1;
	while(i<=N){
		 if(p[i]>=q[j] && p[i]<=q[j+1]){
		 	i++;
		 }
		 else{
			j+=2;
			q[j] = p[i];
			q[j+1] = p[i]+L-1;
			i++;
			count++;
		 }
	}
	cout<<count;
	return 0;
}
