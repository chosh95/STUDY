/*
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
int stack[10001], t = -1;
void push(int x)
{
	stack[++t] = x;
}
void pop(void)
{
	if(t==-1) cout<<"-1"<<endl;
	else{
		cout<<stack[t]<<endl;
		stack[t--] = NULL;
	}
}
void size(void)
{
	cout<<t+1<<endl;
}
void empty(void)
{
	if(t==-1) cout<<"1"<<endl;
	else cout<<"0"<<endl;
}
void top(void)
{
	if(t==-1) cout<<"-1"<<endl;
	else	cout<<stack[t]<<endl;
}

int main()
{
	int N,num;
	cin>>N;
	string a("pop");
	string b("size");
	string c("empty");
	string d("top");
	for(int i=1;i<=N;i++){
		string e;
		cin>>e;
		if(e==a)	pop();
		else if(e==b) size();
		else if(e==c) empty();
		else if(e==d) top();
		else{
			cin>>num;
			push(num);
		}
	}
}
*/
