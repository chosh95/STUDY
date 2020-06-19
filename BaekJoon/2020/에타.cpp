#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int p[10][10] = {
	{-1,-1,-1,-1,-1,-1},
	{-1,11,5,3,-1,-1}, 
	{-1,3,1,12,7,-1},
	{-1,13,9,3,2,-1},
	{-1,-1,9,7,13,-1},
	{-1,-1,-1,-1,-1,-1}
};
int visit[10][10];

int dx[6] = { -1,0,0,1,-1,1 }; // ���� ���������� �»�, ���, ����, ����, ��, ��� �̵��ϴ� ��ǥ
int dy[6] = { -1,-1,1,1,0,0 };

//���ڿ��� ����ؼ� ����� ��ȯ
int toNum(string str) {
	int num = 0; //���ڿ����� �����ڷ� ������ �� ����. ex) 123 - 45���� 123�� 45�� �̿� �ش�
	stack<int> st; //���ڸ� �����ϴ� ����
	stack<int> op; //�����ڸ� �����ϴ� ����. ���ǻ� ������ 1, �������� 0���� �����ߴ�.

	for (int i = 0; i < str.size(); i++) {
		//������ ��� num �ֽ�ȭ
		if (str[i] - '0' >= 0 && str[i] - '0' < 10) { 
			num *= 10;
			num += (str[i] - '0');
		}

		//�������� ��� num�� st���ÿ� �ְ� �����ڵ� op ���ÿ� �ִ´�.
		else if (str[i] == '-') { 
			st.push(num);
			num = 0;
			op.push(1);
		}
		else if (str[i] == '/') {
			st.push(num);
			num = 0;
			op.push(2);
		}
	}
	//�������� ���� �� �� ���ڵ� �־��ش�.
	if(num !=0) st.push(num); 

	//st�� ������ ����� �� ���� ���� ������ �����Ѵ�.
	while (st.size() > 1) {
		//st�� ���� ���� �� ���� �����ڸ� �̾Ƴ���.
		int b = st.top(); st.pop();
		int a = st.top(); st.pop();
		int oper = op.top(); op.pop();

		//�������� ��� ������ �ٽ� ���ÿ� �־��ش�.
		if (oper == 2) {
			st.push(a / b);
			if (a%b != 0) return -1; // ������ ������ �� �Ǵ� ���� �Ұ����ϹǷ� -1 ��ȯ�ؼ� ������.
		}
		else {
			//������ ����ִٴ� ���� �� a - b ��길 ���Ҵٴ� ���̹Ƿ� ����ϰ� �־��ش�.
			if (st.empty() || op.empty()) { 
				st.push(a - b);
			}

			// aa / a - b ���� ����. a-b�� ���� ����ϸ� ��Ģ���� ������ ���� �����Ƿ� aa/a�� ����ϰ� b�� ����Ѵ�.
			// �̶� st�� empty��� ���� aa / a - b��� ���̰�, empty()�� �ƴ϶�� x - aa / a - b�� �� �� �����Ƿ� b�� ��������Ѵ�.
			else if (op.top() == 2) { 
				op.pop();
				int aa = st.top(); st.pop();
				if (aa%a != 0) return -1;
				if (st.empty())
					st.push(aa / a - b);
				else
					st.push(aa / a + b);
			}
			else if (op.top() == 1) {
				st.push(a + b);
			}
		}
	}
	return st.top();
}

bool isPossible(string str) {
	//��ȣ�� �������� ���ڿ��� 1, 2�� ������. 
	string str1 = "", str2 = "";
	int pos = str.find('=');
	str1 = str.substr(0, pos);
	str2 = str.substr(pos+1);

	//����ó�� : �� ���ڿ��� �����̳� ���� �����ڰ� ������ false
	if (str1[0] == '-' || str1[0] == '/' ||
		str1[str1.size() - 1] == '-' || str1[str1.size() - 1] == '/' ||
		str2[0] == '-' || str2[0] == '/' ||
		str2[str2.size() - 1] == '-' || str2[str2.size() - 1] == '/')
		return false;

	//��ȣ�� �������� ���� ���ڿ��� ����ؼ� ���ڷ� ��ȯ���� �� ���ٸ� true ��ȯ
	if (toNum(str1) == toNum(str2))
		return true;

	return false;
}

void dfs(int x, int y, string str) {
	
	if (str.size() == 14) {
		if (str[0] == '=' || str[str.size() - 1] == '=') return; // ���� ó�� : ���ڿ� �����̳� ���� ��ȣ ������ return
		if(isPossible(str)) //str�� ������ ������ ����ϰ� ������
			cout << str << endl;
		return;
	}
	
	for (int i = 0; i < 6; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny] == 1) continue;
		if (p[nx][ny] == -1) continue;
		visit[nx][ny] = 1;
		if (p[nx][ny] == 11) str += '=';
		else if (p[nx][ny] == 12) str += '/';
		else if (p[nx][ny] == 13) str += '-';
		else str += to_string(p[nx][ny]);
		dfs(nx, ny, str);
		visit[nx][ny] = 0;
		str.erase(str.size()-1);
	}
}

int main()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (p[i][j] == -1) continue;
			if (p[i][j] > 10) continue;
			memset(visit, 0, sizeof(visit));
			visit[i][j] = 1; 
			string tmp = to_string(p[i][j]);
			dfs(i, j, tmp); // ������ ������ ���������� dfs ����
		}
	}
}