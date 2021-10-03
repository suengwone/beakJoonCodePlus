// 파도반 수열

#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int T, N;
	scanf("%d", &T);
	
	vector<long long> arr = { 1,1,1,2,2 };

	while (T--) {
		scanf("%d", &N);
		if (N <= 5)
			printf("%lld\n", arr[N-1]);
		else {
			int size = arr.size();

			for (int i = size; i < N; i++) {
				arr.push_back(arr[i - 1] + arr[i - 5]);
			}

			printf("%lld\n", arr[N - 1]);
		}
	}
}
