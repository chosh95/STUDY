#include <iostream>
#include <math.h>
using namespace std;
void queen(int i);
bool promising(int i);

int N,count=0;
int col[17];

int main()
{
	cin>>N;
	queen(1);
		
	cout<<count;
		
}

void queen(int i)
{
	int j;
	if(promising(i-1)){
		if(i==N+1) count++;
		else{
			for(int j=1;j<=N;j++){
				col[i] = j;	
				queen(i+1);	
			}
		}
	}
}

bool promising(int i)
{
	int k=1;
	bool t=true;
	while(k<i && t){
		if(col[i]==col[k] || abs(col[i]-col[k])==i-k) t=false;
		k++;
	}
	return t;
}
