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

int dx[6] = { -1,0,0,1,-1,1 }; // 각각 육각형에서 좌상, 우상, 좌하, 우하, 좌, 우로 이동하는 좌표
int dy[6] = { -1,-1,1,1,0,0 };

//문자열을 계산해서 결과값 반환
int toNum(string str) {
	int num = 0; //문자열에서 연산자로 나뉘는 각 숫자. ex) 123 - 45에서 123과 45가 이에 해당
	stack<int> st; //숫자를 저장하는 스택
	stack<int> op; //연산자를 저장하는 스택. 편의상 뺄셈은 1, 나눗셈은 0으로 저장했다.

	for (int i = 0; i < str.size(); i++) {
		//숫자인 경우 num 최신화
		if (str[i] - '0' >= 0 && str[i] - '0' < 10) { 
			num *= 10;
			num += (str[i] - '0');
		}

		//연산자인 경우 num을 st스택에 넣고 연산자도 op 스택에 넣는다.
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
	//마지막에 삽입 안 된 숫자도 넣어준다.
	if(num !=0) st.push(num); 

	//st에 마지막 결과값 한 개만 남을 때까지 연산한다.
	while (st.size() > 1) {
		//st의 상위 숫자 두 개와 연산자를 뽑아낸다.
		int b = st.top(); st.pop();
		int a = st.top(); st.pop();
		int oper = op.top(); op.pop();

		//나눗셈인 경우 나눠서 다시 스택에 넣어준다.
		if (oper == 2) {
			st.push(a / b);
			if (a%b != 0) return -1; // 나눗셈 연산이 안 되는 경우는 불가능하므로 -1 반환해서 끝낸다.
		}
		else {
			//스택이 비어있다는 것은 딱 a - b 계산만 남았다는 뜻이므로 계산하고 넣어준다.
			if (st.empty() || op.empty()) { 
				st.push(a - b);
			}

			// aa / a - b 같은 경우다. a-b를 먼저 계산하면 사칙연산 순서에 맞지 않으므로 aa/a를 계산하고 b와 계산한다.
			// 이때 st가 empty라는 것은 aa / a - b라는 것이고, empty()가 아니라면 x - aa / a - b가 될 수 있으므로 b를 더해줘야한다.
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
	//등호를 기준으로 문자열을 1, 2로 나눈다. 
	string str1 = "", str2 = "";
	int pos = str.find('=');
	str1 = str.substr(0, pos);
	str2 = str.substr(pos+1);

	//예외처리 : 각 문자열의 시작이나 끝에 연산자가 있으면 false
	if (str1[0] == '-' || str1[0] == '/' ||
		str1[str1.size() - 1] == '-' || str1[str1.size() - 1] == '/' ||
		str2[0] == '-' || str2[0] == '/' ||
		str2[str2.size() - 1] == '-' || str2[str2.size() - 1] == '/')
		return false;

	//등호를 기준으로 나눈 문자열을 계산해서 숫자로 반환했을 때 같다면 true 반환
	if (toNum(str1) == toNum(str2))
		return true;

	return false;
}

void dfs(int x, int y, string str) {
	
	if (str.size() == 14) {
		if (str[0] == '=' || str[str.size() - 1] == '=') return; // 예외 처리 : 문자열 시작이나 끝에 등호 있을시 return
		if(isPossible(str)) //str이 정답을 만들어내면 출력하고 끝내기
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
			dfs(i, j, tmp); // 숫자인 지점을 시작점으로 dfs 조사
		}
	}
}