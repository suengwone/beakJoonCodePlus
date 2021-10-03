// 파도반 수열

#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int T, N;
	scanf("%d", &T);
	
	// 수열의 규칙 : P(N) = P(N-1) + P(N-5)
	// 규칙으로 인해 앞 5개 원소는 따로 입력
	vector<long long> arr = { 1,1,1,2,2 };
	// N이 최대 100까지 들어가게 되는데 값이 int 자료형 크기보다 커지기 때문에
	// long long 자료형으로 vector를 만듬

	// T번 반복
	while (T--) {
		scanf("%d", &N);

		// vector에 5개의 값이 들어가 있기 때문에 5를 기준으로 나눔
		if (N <= 5)
			printf("%lld\n", arr[N-1]);

		// 기존의 값보다 큰 인덱스의 값을 가져와야 한다면
		else {
			// 구해놓은 값에서 필요한 부분만 더 구하기 위해 크기를 받아줌
			int size = arr.size();

			// 기존에 구해놓은 마지막 인덱스 다음부터 시작
			for (int i = size; i < N; i++) {
				// 수열 규칙 : P[N] = P[N-1] + P[N-5]
				arr.push_back(arr[i - 1] + arr[i - 5]);
			}

			// 실제 인덱스는 1씩 작기 때문에 N-1의 값을 출력
			printf("%lld\n", arr[N - 1]);
		}
	}
}
