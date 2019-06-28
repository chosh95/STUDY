#include <iostream>
#include <algorithm>
using namespace std;
struct time{
	int start;
	int end;
};

bool cmp_time(time a,time b);

int main()
{
	int N;	//ȸ���� �� 
	cin>>N;
	time a[N+1]; 
	for(int i=1;i<=N;i++){
		cin>>a[i].start;
		cin>>a[i].end;
	}
	sort(a+1,a+N+1,cmp_time);
	int min_end = a[1].end; // ���� ���� ���� ������ ȸ�� �ð� ��Ͽ� 
	int count = 1;	// �ִ� ȸ�� �� ��Ͽ� 
	for(int i=2;i<=N;i++){
		if(a[i].start >= min_end){ 
			min_end = a[i].end;
			++count;
		}
	}
	cout<<count;
}
bool cmp_time(time a,time b) //����ü time �ð� ��  
{
	if(a.end<b.end) return true; 
	else if(a.end==b.end) return a.start<b.start; //������ �ð��� ������ 
	else return false; //���� �����ϴ°� ������ ����
}
