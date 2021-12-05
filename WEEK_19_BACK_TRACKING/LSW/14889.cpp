// 스타트와 링크

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> team_stat;
int N, answer = 2000;

int solution(vector<int> team) {
	int answer = 0;
	for (int i = 0; i < N / 2 - 1; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			answer += team_stat[team[i]][team[j]] + team_stat[team[j]][team[i]];
		}
	}
	return answer;
}

int main(void) {
	scanf("%d", &N);

	team_stat = vector<vector<int>>(N, vector<int>(N));
	vector<int> check = vector<int>(N,false);
	vector<int> team_1, team_2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &team_stat[i][j]);
		}
	}

	for (int i = 0; i < N / 2; i++) {
		check[i] = true;
	}

	do {
		for (int i = 0; i < N; i++) {
			if (check[i]) team_1.push_back(i);
			else team_2.push_back(i);
		}
		int differnce = solution(team_2) - solution(team_1);
		if (differnce < 0) differnce = -differnce;
		if (answer > differnce) answer = differnce;
		team_1.clear();
		team_2.clear();

		if (answer == 0) break;
	} while (prev_permutation(check.begin(),check.end()));

	printf("%d\n", answer);
}
