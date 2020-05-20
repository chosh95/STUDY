#include <string>
#include <vector>
#include <iostream>
using namespace std;

string fun(string w) {
	string u, v;

	//1�� �ܰ�
	if (w == "") return "";

	//2�� �ܰ�
	for (int acnt = 0,bcnt=0, i = 0; i < w.size(); i++) {
		if (w[i] == '(') acnt++;
		else bcnt++;
		if (acnt == bcnt) { //�������� ��ȣ ���ڿ��� �и�
			u = w.substr(0,i+1);
			v = w.substr(i + 1);
			break;
		}
	}

	//u�� �ùٸ� ��ȣ ���ڿ����� �˻�
	int cnt = 0;
	for (int i = 0; i < u.size(); i++){
		if (cnt==0 && u[i] == ')') {
			cnt++;
			continue;
		}
		if (u[i] == '(') cnt++;
		else cnt--;
	}

	if (cnt == 0) {
		//3�� �ܰ�
		v = fun(v);
		//3.1�� �ܰ�
		return u + v;
	}

	//4�� �ܰ�
	else {
		string tmp = "("; //4.1
		tmp += fun(v); //4.2
		tmp += ")"; //4.3
		u.erase(0,1); //4.4
		u.erase(u.size()-1,1);
		for (int i = 0; i < u.size(); i++) {
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		return tmp + u; //4.5
	}
}

string solution(string p) {
	string answer = "";
	answer = fun(p);
	return answer;
}

int main()
{
	cout << solution(")(") << endl;
	cout << solution("(()())()") << endl;
	cout << solution("()))((()");
}