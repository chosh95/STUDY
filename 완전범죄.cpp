/*
#include <iostream>
using namespace std;
int p[100001];
int N,S,D,F,B,K,count=0;
void crime(int prepo,int polpo,int front);
int main()
{
	cin>>N>>S>>D>>F>>B>>K;
	for(int i=0;i<K;i++) cin>>p[i];
	crime(S,0,F);
	if(count!=-1) cout<<count;
	else cout<<"BUG FOUND";
	
}
void crime(int prepo,int polpo,int front)
{
	if(front==0) count = -1;
	if(D-prepo<=F) count++;
	if(prepo+front!=p[polpo]){
		if(prepo+front>p[polpo]){
			count++;
			crime(prepo+front,polpo+1,front);
		}
		else{
			count++;
			crime(prepo+front,polpo,front);
		}
	}
	else
		crime(prepo,polpo,front-1);	
}
*/
