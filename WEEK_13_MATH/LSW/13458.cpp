// 시험 감독

#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, B, C;
	long long int answer = 0;

	scanf("%d", &N);

	vector<int> Ai(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Ai[i]);
	}

	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		// 총감독관은 한명씩 무조건 들어가야하기 때문에
		// 총인원수에서 총감독관이 감시 가능한 응시자의 수를 뺌
		answer += 1;
		Ai[i] -= B;

		// 뺀 응시자수가 마이너스가 되면 다음으로 넘어간다
		if (Ai[i] <= 0) continue;

		// 남은 응시자수를 부감독관이 감시 가능한 인원으로 나눠 0이 되면
		// 나눈 몫을 결과값에 더해주고
		// 0이 아니면 나눈몫에 1을 더해 더함
		if (Ai[i] % C == 0)
			answer += Ai[i] / C;
		else
			answer += (Ai[i] / C) + 1;
	}

	printf("%lld\n", answer);
}
