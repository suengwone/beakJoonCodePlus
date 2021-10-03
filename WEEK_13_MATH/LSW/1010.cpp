// 다리 놓기

#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	// 조합 문제
	// 출력값 = M(combi)N = (M * (M-1) * (M-2) ... * (M - N + 1)) / (1 * 2 * 3 ... * N)
	int N, M, divider;
	long long answer;

	// 테스트 케이스 T번 반복
	while (T--) {
		answer = 1;
		scanf("%d %d", &N, &M);

		// N이 M의 절반보다 커지면 N은 N-M (조합 공식)
		N > M / 2 ? N = M - N : N;

		// 그냥 연산을 하면 값이 너무 커지기 때문에 나눌 수 있는 값은 먼저 나눔
		divider = N;
		// 나눠야할 값중 가장 큰 값이 N부터 나누기 시작
		for (int i = 0; i < N; i++) {
			// answer에 M부터 시작하여 M-N+1까지 곱해줌
			answer *= (M - i);

			// 곱해지는 중간에 나눠야할 값이 현재 값에 나누어 떨어진다면
			// 또는 나눠야할 값이 0이 아니라면 나눌 수 있을 만큼 나누고 다시 반복
			while (divider != 0 && answer % divider == 0) {
				answer /= divider;
				divider--;
			}
		}
		
		// 결과값 출력
		printf("%lld\n", answer);
	}
}
