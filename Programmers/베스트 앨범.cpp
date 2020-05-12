#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool cmp(pair<string,int> a,pair<string,int> b) {
	return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int>b) {
	return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	
	map<string, int> m1;
	vector<pair<string,int>> genre_list;

	for (int i = 0; i < genres.size(); i++) 
		m1[genres[i]] += plays[i];

	map<string, int>::iterator it = m1.begin();
	for (it=m1.begin(); it != m1.end(); it++) 
		genre_list.push_back({ it->first,it->second });

	sort(genre_list.begin(),genre_list.end(), cmp);
	for (int i = 0; i < genre_list.size(); i++) {
		vector<pair<int, int>> music_list;
		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] != genre_list[i].first) continue;
			music_list.push_back({ plays[j],j });
		}
		sort(music_list.begin(), music_list.end(), cmp2);
		answer.push_back(music_list[0].second);
		if (music_list.size() >= 2) answer.push_back(music_list[1].second);
	}

	return answer;
}

int main()
{
	vector<int> ans = solution({"classic","pop","classic","classic", "pop"}, {500,600,150,800,2500});
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}