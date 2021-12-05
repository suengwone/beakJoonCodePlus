// 알파벳

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board;
vector<char> check;
vector<vector<int>> board_check;
vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
int answer = 0, R, C;

void solution(int cnt,int col, int row) {
	for (int i = 0; i < 4; i++) {
		int next_col = col + dir[i].first;
		int next_row = row + dir[i].second;
		if (next_col >= R || next_row >= C || next_col < 0 || next_row < 0) continue;
		if (find(check.begin(), check.end(), board[next_col][next_row]) != check.end())
			continue;
		else {
			check.push_back(board[next_col][next_row]);
			board_check[next_col][next_row] = true;
			solution(cnt + 1, next_col, next_row);
			board_check[next_col][next_row] = false;
			check.pop_back();
		}
	}

	if (answer < cnt) answer = cnt;

	return;
}

int main(void) {
	scanf("%d%d", &R, &C);
	board = vector<vector<char>>(R, vector<char>(C));
	board_check = vector<vector<int>>(R, vector<int>(C, false));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	check.push_back(board[0][0]);
	board_check[0][0] = true;
	solution(1,0,0);

	printf("%d\n", answer);
}
