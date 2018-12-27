/*
#include <iostream> 
using namespace std;
int meeting(int max_index,int current_value,int count_num);
bool promising(int max_index,int current_value);
int p[100001][2];
int main()
{
	int N=0,current=0,count=1,t=1;
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=0;j<2;j++){
			cin>>p[i][j];
		}
	}
	
	current = p[1][1];
	for(int i=1;i<=N;i++){
		if(p[i][1]<current){
			current = p[i][1];
			t = i;
		}
		else continue;
	}
	
	p[t][1] = -1;
	count = meeting(N,current,count);
	cout<<count;	
	
	return 0;
}

int meeting(int max_index,int current_value,int count_num)
{
	if(promising(max_index,current_value)){
		int count=0,t=0;
		int tmp=0;
		for(int i=1;i<=max_index;i++){
			if(count == 0 && p[i][1]>=current_value && p[i][0]>=current_value ){
				tmp = p[i][1];
				count = 1;
				t = i;
			}
			else if(count == 1 && p[i][1]>=current_value && p[i][0]>=current_value) {
				if(p[i][1] != -1 && p[i][1]<=tmp){ 
					tmp = p[i][1];
					t = i;
				}
			}
			else continue;
		}
		p[t][1] = -1;
		
		meeting(max_index,tmp,++count_num);	
	} 
	else return count_num;
}

bool promising(int max_index,int current_value)
{
	bool tmp = false;
	for(int i=1;i<=max_index;i++){
		if(p[i][1]>=current_value && p[i][0]>=current_value){
			tmp = true;
			break;
		}
	}
	return tmp;	
}
*/
