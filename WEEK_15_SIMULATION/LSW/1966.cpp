// 프린터 큐

#include <cstdio>
#include <deque>

using namespace std;

int main() {
	int T, N, M, imp, tmp, count, answer;
	scanf("%d", &T);

	// 큐를 사용하면서 begin과 end를 사용하기 위해 deque 사용
	deque<int> que;

	// T만큼 반복
	while (T--) {
		// 출력한 횟수 count 초기화
		count = 0;
		// 출력해야 하는 값 answer (큐 크기가 1일때를 위해 1로 초기화)
		answer = 1;
		scanf("%d %d", &N, &M);

		// N개의 큐 내부의 값을 입력받음
		for (int i = 0; i < N; i++) {
			scanf("%d", &imp);
			que.push_back(imp);
		}

		// 큐가 비어있을때까지 반복
		while (!que.empty()) {
			// 큐의 첫번째 값을 tmp에 저장
			tmp = que.front();
			// 큐의 첫번째 값을 뺌
			que.pop_front();
			// 찾아야하는 인덱스 M에서 1을 뺌 (큐의 첫번째 값이 빠졌기 때문에 인덱스인 M - 1을 함)
			M -= 1;

			// 큐안에 있는 값을 조회
			for (auto i = que.begin(); i != que.end(); i++) {
				// 큐의 첫번째 값인 tmp보다 큐 내부의 값이 크면
				if (tmp < *i) {
					// 큐의 맨뒤로 tmp 값을 추가
					que.push_back(tmp);
					// M이 -1이면 인덱스인 M의 값을 변경 (큐의 사이즈 - 1)
					if (M == -1) M = que.size() - 1;
					// 큰 값이 나온다면 반복 탈출
					break;
				}
			}

			// 위의 반복문에서 tmp보다 큰 값이 없는 경우 큐의 크기가 작아짐
			// count값과 큐의 크기랑 더했을때 N과 다르면
			if (count + que.size() != N) {
				// count + 1
				count++;
			}

			// M이 -1이라면 answer값에 count를 입력하고 탈출
			if (M == -1) {
				answer = count;
				break;
			}
		}

		printf("%d\n", answer);
	}
}
