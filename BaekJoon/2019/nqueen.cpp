/*
#include <iostream>
#include <math.h>
using namespace std;
int N,count;
int col[16];
void queen(int n);
bool promising(int n);

int main()
{
	cin>>N;
	count = 0;
	queen(1);
	cout<<count;
}

void queen(int n)
{
	if(promising(n)){
		if(n==N+1) count++; 
		else{
			for(int i=1;i<N+1;i++){
				col[n] = i;
				queen(n+1);
			}
		}
	}
}

bool promising(int n)
{
	bool tmp = true;
	for(int i=1;i<n-1;i++)
			if(col[i]==col[n-1] || abs(col[i]-col[n-1]) == n-1-i) tmp = false;
		
	return tmp;
}
	
*/
