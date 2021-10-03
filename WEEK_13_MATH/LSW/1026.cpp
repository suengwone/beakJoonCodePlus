// 보물

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, answer = 0;
	
	scanf("%d", &N);

	vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	// A와 B를 오름차순으로 정렬
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	// A는 정방향, B는 역방향으로 순회하며 두개를 곱해주고 answer에 더함
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[N - i - 1];
	}

	printf("%d\n", answer);
}
