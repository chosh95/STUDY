#include <iostream>
#include <string>
using namespace std;
int q[10005];
int front,rear=0;
void pop(){
	if(q[front]==0) cout<<"-1"<<endl;
	else{
		cout<<q[front]<<endl;
		q[front]=0;
		if(front<rear) front++;
	}
}
void size(){
	if(rear==front && q[rear]==0) cout<<"0"<<endl;
	else cout<<(rear-front+1)<<endl;
}
void empty(){
	if(rear==front && q[front]==0) cout<<"1"<<endl;
	else cout<<"0"<<endl;
}
void frontt(){
	if(q[front]!=0) cout<<q[front]<<endl;
	else cout<<"-1"<<endl;
}
void back(){
	if(q[rear]!=0) cout<<q[rear]<<endl;
	else cout<<"-1"<<endl;
}
void push(int x){
	if(front==rear && q[rear]==0){
		q[front]=x;
	}
	else{
		q[++rear]=x;
	}
}

int main()
{
	int N,x;
	cin>>N;
	string str;
	for(int i=1;i<=N;i++){
		cin>>str;
		if(str=="pop") pop();
		else if(str=="front") frontt();
		else if(str=="back") back();
		else if(str=="empty") empty();
		else if(str=="size") size();
		else{
			cin>>x;
			push(x);
		}
	}	
}
