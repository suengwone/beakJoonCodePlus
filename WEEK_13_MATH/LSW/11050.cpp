// 이항 계수1

#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	// 이항계수
	// N=0          1
	// N=1        1  1
	// N=2       1  2  1
	// N=3      1  3  3  1
	// N=4     1 4  6  4  1
	// N=5    1 5 10 10  5 1 
	//      k=1,2, 3, 4, 5 ,6
	
	// 2차원 벡터 N+1 크기로 선언 
	vector<vector<int>> arr(N+1);
	// 가장 상단에 1을 입력
	arr[0].push_back(1);

	// N=1부터 규칙대로 입력
	for (int i = 1; i <= N; i++) {
		// 첫번째 원소는 1
		arr[i].push_back(1);
		// 중간값은 이전 열의 연속되는 값 두개를 더해서 입력
		for (int j = 1; j < i; j++) {
			arr[i].push_back(arr[i - 1][j - 1] + arr[i - 1][j]);
		}
		// 마지막 원소는 1
		arr[i].push_back(1);
	}

	printf("%d\n", arr[N][K]);
}
