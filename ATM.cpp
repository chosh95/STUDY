/*
#include <iostream> 
using namespace std;
void bubblesort(int arr[],int size);

int main()
{
	int N,res=0;
	int p[1001];
	cin>>N;
	for(int i=0;i<N;i++) cin>>p[i];
	bubblesort(p,N);
	if(N!=1){
		bubblesort(p,N);
		for(int i=1;i<N;i++) p[i]+=p[i-1];
	}
	for(int i=0;i<N;i++) res+=p[i];
	cout<<res;
	return 0;
}

void bubblesort(int arr[],int size){
	bool isSwap;
	do{
		isSwap = false;
		for(int i=1;i<size;i++){
			if(arr[i-1]>arr[i]){
				swap(arr[i-1],arr[i]);
				isSwap = true;
			}
		}
	}while(isSwap);
}
*/
