#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int C, N, Q, a, b;
const int MAX = numeric_limits<int>::max();
//const int MIN = numeric_limits<int>::min();
/*
struct Tree {
	int size;
	vector<pair<int, int>> range; //range[i] = (min,max) i번째 노드의 최소, 최대값
	Tree(const vector<int> & p) {
		size = N;
		range.resize(N * 4);
		init(p, 0, N - 1, 1);
	}
	pair<int,int> init(const vector<int> & p, int left, int right, int node) {
		if (left == right)
			return range[node] = {p[left],p[left]};
		int mid = (left + right) / 2;
		range[node].first = min(init(p, left, mid, node * 2).first, init(p, mid + 1, right, node * 2 + 1).first);
		range[node].second = max(init(p, left, mid, node * 2).second, init(p, mid + 1, right, node * 2 + 1).second);
		return range[node];
	}
	pair<int, int> query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return { MAX,MIN };
		if (left <= nodeLeft && nodeRight <= right)
			return range[node];
		int mid = (nodeLeft + nodeRight) / 2;
		int tmp_min = min(query(left, right, node * 2, nodeLeft, mid).first, query(left, right, node * 2 + 1, mid + 1, nodeRight).first);
		int tmp_max = max(query(left, right, node * 2, nodeLeft, mid).second, query(left, right, node * 2 + 1, mid + 1, nodeRight).second);
		return { tmp_min,tmp_max };
	}
	pair<int, int> query(int left, int right) {
		return query(left, right, 1, 0, N - 1);
	}
};*/
struct RMQ{
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& array){
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	int init(const vector<int>& array, int left, int right, int node)
	{
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight){
		if (right < nodeLeft || nodeRight < left)
			return MAX;
		//node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	//query()를 외부에서 호출하기 위한 인터페이스

	int query(int left, int right){
		return query(left, right, 1, 0, n - 1);
	}
};


int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> Q;
		vector<int> p;
		vector<int> minusP;
		for (int tmp, i = 0; i < N; i++) {
			cin >> tmp;
			p.push_back(tmp);
			minusP.push_back(-tmp);
		}
		RMQ t(p);
		RMQ minusT(minusP);
		while (Q--) {
			cin >> a >> b;
			int low = t.query(a, b);
			int high = abs(minusT.query(a, b));
			cout << high-low << "\n";
		}
	}
}