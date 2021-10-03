// 날짜 계산

#include <cstdio>

using namespace std;

int main(void) {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int multi = 0, tmp;

	// 1<=E<=15 , 1<=S<=28 , 1<=M<=19

	while (true) {
		// E를 기준으로 값을 높임
		tmp = multi * 15 + E;

		// E를 기준으로 높힌 값을 S를 빼서 28로 나눠보고
		// M을 빼서 19로 나눈 나머지가 0일때 반복문 탈출
		if ((tmp-S) % 28 == 0 && (tmp-M) % 19 == 0)
			break;
		// 조건이 맞지 않으면 tmp 값을 높힐 multi 값을 1씩 증가
		else
			multi++;
	}

	printf("%d\n", tmp);
}
