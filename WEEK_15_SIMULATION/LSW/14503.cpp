// 로봇 청소기

#include <cstdio>
#include <vector>

using namespace std;

// 출려해야할 결과값
int answer = 0;

// 방향
pair<int, int> dir[] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

// 2차원 벡터 (벽인지 빈칸인지 구분 및 청소 여부 체크)
vector<vector<pair<int, bool>>> arr;

// 좌표값에 청소를 했는지 또는 벽인지 체크하는 함수
bool validate(pair<int,int> Pair) {
	// 청소를 했는지 체크
	if (arr[Pair.first][Pair.second].second == true)
		return false;
	// 벽인지 체크
	else if (arr[Pair.first][Pair.second].first == 1)
		return false;
	else
		return true;
}

// 좌표값으로 pair를 사용하는데 더하기를 쉽게 하기 위해 만든 함수
pair<int, int> plusPair(pair<int, int> a, pair<int, int> b) {
	return pair<int, int>(a.first + b.first, a.second + b.second);
}

// 시작점부터 청소하는 함수
void clean(int count, pair<int,int> pos, int dir_num) {
	// 들어온 좌표의 청소 여부를 true로 바꿈
	arr[pos.first][pos.second].second = true;

	// 바라보는 방향 왼쪽으로 만들기
	dir_num = (dir_num + 3) % 4;

	// 다음 좌표값을 구함
	pair<int, int> nextPos = plusPair(pos, dir[dir_num]);

	// 다음 좌표값의 가능 여부 확인 후 재귀 (count + 1)
	if (validate(nextPos)) {
		clean(count+1, nextPos, dir_num);
	}
	// 다음 좌표값이 불가능하면 
	else {
		// 3번 반복하면서 남은 방향에 대한 가능 여부 체크
		for (int i = 0; i < 3; i++) {
			dir_num = (dir_num + 3) % 4;
			nextPos = plusPair(pos, dir[dir_num]);
			if (validate(nextPos)) {
				clean(count+1, nextPos, dir_num);
				return;
			}
		}
		
		// 모든 방향이 불가능하면 현재 바라보는 방향에서 후진
		nextPos = plusPair(pos, { -dir[dir_num].first,-dir[dir_num].second });
		// 후진하는 좌표가 벽이라면 answer값에 count를 집어넣음
		if (arr[nextPos.first][nextPos.second].first == 1) {
			answer = count;
		}
		// 후진하는 좌표가 벽이 아니면 다시 진행하되 count는 그대로 재귀
		else {
			clean(count, nextPos, dir_num);
		}
	}
}

int main() {
	int N, M, r, c, d;
	pair<int, bool> check(0, false);

	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &r, &c, &d);

	// 전역으로 선언한 2차원 벡터 arr를 행 N크기만큼 열 M 크기만큼 선언
	arr = vector<vector<pair<int, bool>>>(N, vector<pair<int, bool>>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &check.first);
			arr[i][j] = check;
		}
	}

	// 시작값 주어진 좌표를 pair로 넣어주고 시작값에서 청소를 하기 때문에 count를 1로 시작
	clean(1, pair<int, int>(r, c), d);

	printf("%d\n", answer);
}
