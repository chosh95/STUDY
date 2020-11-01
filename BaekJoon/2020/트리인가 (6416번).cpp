#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <set>
using namespace std;


int main()
{
	for (int k = 1;; k++) {
		set<int> nodes;
		bool isPossible = true;
		int sum = 0;

		while(true){
			int u, v;
			cin >> u >> v;
			if (u == 0 && v == 0) break;
			if (u == -1 && v == -1) return 0;
			nodes.insert(u);
			nodes.insert(v);
			sum++;
		}

		if (sum == 0 || sum + 1 == nodes.size())
			cout << "Case " << k << " is a tree.\n";
		else
			cout << "Case " << k << " is not a tree.\n";
	}
}