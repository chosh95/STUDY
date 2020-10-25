#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int visit[11][11];
vector<int> res;

void bfs(int a, int b, int size, int** matrix) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= size || ny >= size) continue;
			if (matrix[nx][ny] == 0 || visit[nx][ny] == 1) continue;
			q.push({ nx,ny });
			visit[nx][ny] = 1;
			cnt++;
		}
	}

	res.push_back(cnt);
}

void solution(int sizeOfMatrix, int** matrix) {
	for (int i = 0; i < sizeOfMatrix; i++)
		for (int j = 0; j < sizeOfMatrix; j++)
			if (matrix[i][j] == 1 && visit[i][j] == 0)
				bfs(i, j, sizeOfMatrix, matrix);

	if (res.size() == 0) cout << 0 << endl;
	else {
		sort(res.begin(), res.end());
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i != res.size() - 1) cout << " ";
		}
	}
}

struct input_data {
	int sizeOfMatrix;
	int** matrix;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.sizeOfMatrix;

	inputData.matrix = new int* [inputData.sizeOfMatrix];
	for (int i = 0; i < inputData.sizeOfMatrix; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		inputData.matrix[i] = new int[inputData.sizeOfMatrix];
		for (int j = 0; j < inputData.sizeOfMatrix; j++) {
			iss >> inputData.matrix[i][j];
		}
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.sizeOfMatrix, inputData.matrix);
	return 0;
}