// 외판원 순회2

#include <iostream>

using namespace std;

int city_cost[11][11];
int check[11] = { false, };
int answer = 10000000;
int N;


void solution(int start_city, int cur_city, int travel_count, int cur_cost) {
	if (travel_count >= N) {
		if (answer > cur_cost && cur_city == start_city) {
			answer = cur_cost;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (city_cost[cur_city][i] == 0) continue;
		if (check[i] == false) {
			check[i] = true;
			if(answer >= cur_cost)
				solution(start_city, i, travel_count + 1, cur_cost + city_cost[cur_city][i]);
			check[i] = false;
		}
	}
	return;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &city_cost[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		solution(i, i, 0, 0);
	}

	printf("%d\n", answer);
}
