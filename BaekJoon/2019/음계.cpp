#include <iostream>
using namespace std;
int p[10];
int main()
{
	bool asc=true,des=true;
	for(int i=1;i<=8;i++)	cin>>p[i];
	if(p[1]==1){
		for(int i=2;i<=8;i++){
			if(p[i-1]<p[i]) continue;
			else asc = false;
		}
		if(asc) cout<<"ascending";
	}
	if(p[1]==8){
		for(int i=2;i<=8;i++){
			if(p[i-1]>p[i]) continue;
			else des = false;
		}
		if(des) cout<<"descending";
	}
	if(!asc || !des){
		cout<<"mixed";
	}
}
