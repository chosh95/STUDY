/*
#include <iostream>
using namespace std;
int arr[302] = {0};
bool barr[302] = {0};

int main()
{
	int N,res=0;
	cin>>N;
	for(int i=0;i<N;i++) 	cin>>arr[i+1];
 	for(int i=N;i>0;i--)	boolarr(i,N);
	for(int i=0;i<N;i++){
		if(barr[i]==1) res += arr[i];
	}
	cout<<res;
	return 0;	
}

void boolarr(int currentPos,int finalPos){
	if(currentPos==finalPos) barr[currentPos] = true;
	if(currentPos==finalPos-1){
		if(arr[currentPos-1] < arr[currentPos]) barr[currentPos] = true;
		else if(barr[currentPos-2]) barr[currentPos] = true;
		else barr[currentPos] = false;
	}
	if(currentPos==finalPos-2){
		if(barr[currentPos+1]) barr[currentPos] = false;
		else barr[currentPos] = true;
	} 
	
}
*/
