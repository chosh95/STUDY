/*
#include <iostream>
#include <string>
using namespace std;
int h[5];
void print(void);
void swaparr(char P);
void swap(int a, int b);
int main()
{
	string p;
	h[1]=1; h[2]=0; h[3]=0; h[4]=2;
	cin>>p;
	int i=0;
	while(p[i]=='A' || p[i]=='B'||p[i]=='C' || p[i]=='D'||p[i]=='E' || p[i]=='F'){
		swaparr(p[i++]);
	}
	print();
}

void swaparr(char P)
{
	if(P=='A') swap(1,2);
	else if(P=='B') swap(1,3);
	else if(P=='C') swap(1,4);
	else if(P=='D') swap(2,3);
	else if(P=='E') swap(2,4);
	else if(P=='F') swap(3,4);
}

void swap(int a,int b)
{
	int tmp = h[a];
	h[a] = h[b];
	h[b] = tmp; 
}

void print(void)
{
	for(int i=1;i<=4;i++) if(h[i]==1){cout<<i<<endl; break;}
	for(int i=1;i<=4;i++) if(h[i]==2){cout<<i<<endl; break;}
}
*/
